#include <iostream>

template<class T>
class NamedObject {
public:
    NamedObject(std::string& name, const T& value) : namedValue(name), objectVaule(value) {
        std::cout << "construt " << std::endl;
    }

    void operator= (const NamedObject<T>& A) {
        std::cout << "operator = " << std::endl;
        namedValue = A.namedValue;
//        objectVaule = A.objectVaule;
    }

    void out() {
        std::cout << "namedValue = " << this->namedValue <<
            "\nobjectVaule = " << this->objectVaule << std::endl;
    }

private:
    std::string& namedValue;
    const T objectVaule;
};

int main() {
    std::string newDog("Persephone");
    std::string oldDog("Satch");
    NamedObject<int> p(newDog, 2);
    NamedObject<int> s(oldDog, 36);

    p = s;

    p.out();
    return 0;
}
