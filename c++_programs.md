1.How many times will the constructor be called?
```c
  #include <iostream>
using namespace std;

class Test {
public:
    Test() { cout << "Constructor called\n"; }
};

int main() {
    Test t1, t2;
    return 0;
}
````
Answer:
<details>
<summary>Show Answer </summary>
Twice — once for each object (t1 and t2).
</details>

2.In what order will destructors be called?
```c
#include <iostream>
using namespace std;

class Demo {
public:
    Demo() { cout << "Constructor\n"; }
    ~Demo() { cout << "Destructor\n"; }
};

int main() {
    Demo d1, d2;
    cout << "Main running\n";
    return 0;
}
```
<details>
<summary>Show Answer </summary>
Answer:
Reverse order of creation →
Output:

Constructor
Constructor
Main running
Destructor
Destructor
</details>

3.What will be the output?
```c
#include <iostream>
using namespace std;

class Car {
public:
    Car(int s) { cout << "Speed = " << s << endl; }
};

int main() {
    Car c1(50), c2(100);
    return 0;
}
```
<details>
<summary>Show Answer </summary>
Answer:

Speed = 50
Speed = 100

</details>
4.Default vs Parameterized Constructor?
```c
#include <iostream>
using namespace std;

class Box {
public:
    Box() { cout << "Default\n"; }
    Box(int x) { cout << "Parameterized " << x << endl; }
};

int main() {
    Box b1, b2(10);
    return 0;
}
```
<details>
<summary>Show Answer </summary>
Output:

Default
Parameterized 10

</details>
5.When will destructor run?
```c
#include <iostream>
using namespace std;

class Temp {
public:
    Temp() { cout << "Start\n"; }
    ~Temp() { cout << "End\n"; }
};

int main() {
    cout << "Main begin\n";
    {
        Temp t;
    }
    cout << "Main end\n";
    return 0;
}
```
<details>
<summary>Show Answer </summary>
Answer:

Main begin
Start
End
Main end
</details>
