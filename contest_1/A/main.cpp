#include <iostream>

using namespace std;

typedef int handle_t;
const handle_t kNullHandle = 0;

void raw_write(handle_t handle, const std::string& content);

void raw_close(handle_t handle);

class IOWrapper {
    handle_t handle;

public:
    explicit IOWrapper(handle_t&& handle): handle(handle) {};

    IOWrapper() = delete;                                              // отсутствие конструктора по умолчанию
    IOWrapper(const IOWrapper& temp) = delete;                         // отсутствие конструктора копирования
    IOWrapper& operator=(const IOWrapper& temp) = delete;              // отсутствие оператора копирования присваиванием

    void Write(const std::string& content) const{                      // метод Write
        if(handle != kNullHandle)
            raw_write(handle, content);
    }

    ~IOWrapper() {
        if(handle != kNullHandle) {
            raw_close(handle);
        }
    }
};

int main() {

    return 0;
}