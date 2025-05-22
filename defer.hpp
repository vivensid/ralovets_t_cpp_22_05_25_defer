#include <iostream>
#include <functional>


class Defer {
  private:
  std::function<void()> ini_func_;

  public:
  Defer() = delete;

  Defer(const Defer& other) = delete;

  Defer(Defer& other) = delete;

  Defer& operator=(Defer& other) = delete;

  Defer& operator=(const Defer& other) = delete;

  Defer(std::function<void()> func) : ini_func_(func) {}

  ~Defer() {
    if(ini_func_) {
      ini_func_();
    }
  }

};

int main() {
  int* array = new int[8];
  Defer example([array]() {
    std::cout << "example was destroyed, function was called" << std::endl;
  });

  {
    /* in this scope example must be destroyed
    if this done, you will see message: "example was destroyed, function was called" */
  
  }

  return 0;
}