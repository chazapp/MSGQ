#ifndef		MSGQ_HPP_
#define		MSGQ_HPP_

#include <list>
#include <mutex>
#include <condition_variable>

template <class T>
class MSGQ {
public:
  MSGQ() {
    this->usage = true;
  }
  ~MSGQ() {}

  void		addElem(T item) {
      std::unique_lock<std::mutex> lck(this->q_mtx);
      this->queue.push_back(item);
      this->cond_v.notify_one();
  }
  
  T		popElem() {
     std::unique_lock<std::mutex> lck(q_mtx);
     if (this->queue.size() == 0)
       cond_v.wait(lck);
     if (this->getUsage() == false)
       return (NULL);
     T item = queue.front();
     queue.pop_front();
     return (item);
  }

  int		getSize() {
     this->q_mtx.lock();
     int size = queue.size();
     this->q_mtx.unlock();
     return (size);
  }
  
  void		setUsage(bool c) {
     if (c == false) {
       this->cond_v.notify_all();
     }
     usage = c;
  }
  bool		getUsage() {
     return (usage);
  }
private:
  std::list<T>	queue;
  std::mutex	q_mtx;
  std::condition_variable	cond_v;
  std::unique_lock<std::mutex>	lck;
  bool		usage;
};




#endif
