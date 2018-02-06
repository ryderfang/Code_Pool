// lazy instance
// 缺点：创建和析构的不确定性
// 优点：main()之前创建，保证全局唯一
template <typename T>
class singleton {
  public:
    static T& GetInstance() {
      static T instance;
      return instance;
    }
  
  protected:
    singleton() {}
    ~singleton() {}

  private:
    singleton(const singleton& rhs) = delete;
    singleton& operator=(const singleton& rhs) = delete;
}

// java中的使用枚举实现的单例（线程安全）- effective java
public enum singleton {
  INSTANCE;
  public static singleton GetInstance() {
    return INSTANCE; 
  }
}

// 线程安全的版本（c++）
#include <mutex>
template <typename T>
class Singleton {
public:
    static T& GetInstance() {
        if (instance_ == nullptr) {
            std::mutex mtx;
            mtx.lock();
            std::lock_guard<std::mutex> lck(mtx, std::adopt_lock);
            if (instance_ == nullptr) {
                instance_ = new T();
                atexit(Destroy);
            }
            return *instance_;
        }
        return *instance_;
    }

protected:
    Singleton() {}
    ~Singleton() {}

private:
    Singleton(const Singleton& rhs) {}
    Singleton& operator=(const Singleton& rhs) {}

    static void Destroy() {
        if (instance_ == nullptr) {
            delete instance_;
        }
        instance_ = nullptr;
    }

private:
    static T* volatile instance_;
};

// sample
class MyClass;
MyClass* one = &Singleton<MyClass>::GetInstance();

