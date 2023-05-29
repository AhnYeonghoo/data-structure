#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

struct Student;
std::ostream& operator>>(std::ostream& os, const Student& s);

template<typename T>
class DynamicArray
{
private:
    T* data;
    size_t n;

public:
    DynamicArray(int n)
    {
        this->n = n;
        data = new T[n];
    }

    DynamicArray(const DynamicArray<T>& other)
    {
        n = other.n;
        data = new T[n];

        for (int i = 0; i < n; i++)
            data[i] = other[i];
    }

    friend DynamicArray<T> operator+(const DynamicArray<T>& arr1, DynamicArray<T>& arr2)
    {
        DynamicArray<T> result(arr1.size() + arr2.size());
        std::copy(arr1.begin(), arr1.end(), result.begin());
        std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

        return result;
    }
    
    std::string toString(const std::string& sep = ", ")
    {
        if (n == 0) return "";
        std::ostringstream os;
        
        os << data[0];
        
        for (int i = 1; i < n; i++)
            os << sep << data[i];

        return os.str();
    }



    T& operator[](int index)
    {
        return data[index];
    }

    const T& operator[](int index) const
    {
        return data[index];
    }

    T& at(int index)
    {
        if (index < n)
            return data[index];

        throw "Index out of range";
    }

    size_t size() const
    {
        return n;
    }

    ~DynamicArray()
    {
        delete[] data;
    }
};

struct Student
{
    std::string name;
    int standard;
};

std::ostream& operator>>(std::ostream& os, const Student& s)
{
    return (os << "[" << s.name << ", " << s.standard << "]");
}

int main()
{   
    int n_students;
    cout << "1반 학생 수를 입력하세요: ";
    cin >> n_students;

    DynamicArray<Student> class1(n_students);
    
    for (int i = 0; i < n_students; i++)
    {
        std::string name;
        int standard;
        cout << i + 1 << "번째 학생 이름과 나이를 입력하세요: ";
        cin >> name >> standard;
        class1[i] = Student{name, standard};
    }

    auto class2 = class1;
    cout << "1번을 복사하여 2반 생성: " << class2.toString() << endl;
    
    auto class3 = class1 + class2;
    cout << "1반과 2반을 합쳐 3반 생성: " << class2.toString() << endl;
    return 0;
}