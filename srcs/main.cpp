#include "MSGQ.hpp"
#include "foo.hpp"

#include <string>
#include <thread>
#include <iostream>
#include <functional>

void	worker(MSGQ<Foo*> &queue) {
  int i = 0;
  while (queue.getUsage() == true) {
    Foo *item = new Foo();
    std::string in("Data #");
    in += std::to_string(i);
    item->data = in;
    queue.addElem(item);
    i++;
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
}

int	main(int argc, char *argv[]) {
  MSGQ<Foo*> queue;
  auto thr1 = std::thread(worker, std::ref(queue));
  Foo *item;
  int i = 0;
  while ((item = queue.popElem()) != NULL) {
    std::cout << "Got item with data : " << item->data << std::endl;
    delete (item);
    i++;
    if (i > 10) {
      queue.setUsage(false);
      break;
    }
  }
  thr1.join();
  return 0;
}
