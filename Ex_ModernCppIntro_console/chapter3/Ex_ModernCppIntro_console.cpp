#include <iostream>
#include <memory>
#include <string>

class MyTestClass
{
private:
    std::shared_ptr<std::string> _text;
public:
    MyTestClass()
        : _text(std::make_shared<std::string>("")) {}
    MyTestClass(const std::string& text)
        : _text(std::make_shared<std::string>(text)) {}
    void setText(const std::string& text);
    std::string getText();
    friend std::ostream& operator<<(std::ostream& os, MyTestClass obj);
};

void MyTestClass::setText(const std::string& text)
{
    _text = std::make_shared<std::string>(text);
}

std::string MyTestClass::getText()
{
    return *_text;
}

std::ostream& operator<<(std::ostream& os, MyTestClass obj)
{
    std::cout << obj.getText() << std::endl;
    return os;
}

int main(void)
{
    MyTestClass Hello;
    Hello.setText("Hello world!");
    std::cout << Hello;

    return 0;
}