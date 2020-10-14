// Функция принимает map и значения ключа
// Если ключа нет, то выбрасывает исключение
// Иначе возвращает ссылку на элемент по ключу
#include <map>
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;


template <typename Key, typename Value> Value& GetRefStrict(map<Key, Value>&, Key&);


template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, Key key) {
    if (m.count(key) == 0) {
        throw runtime_error("ERROR");
    }
    return m[key];
}

int main() {
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl;
    return 0;
}