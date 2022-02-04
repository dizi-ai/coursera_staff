#include <string>
#include <list>
#include "test_runner.h"
using namespace std;

class Editor {
public:
    // Реализуйте конструктор по умолчанию и объявленные методы
    Editor()= default;
    void Left(){
        if (pos>0) {
            pos--;
            it--;
        }
    }
    void Right(){
        if (pos<edit.size()) {
            pos++;
            it++;
        }

    }
    void Insert(const char& token){
        edit.insert(it,token);
        it--;
        Right();
    }
    void Cut(size_t tokens = 1){
        buffer.clear();
        auto it2 =it;
        std::advance(it2, tokens);
        if (pos+tokens>edit.size())
            it2=edit.end();
        buffer.splice(buffer.begin(),edit,it,it2);
        it = it2;

    }
    void Copy(size_t tokens = 1){
        buffer.clear();
        std::copy(it, std::next(it, tokens), std::back_inserter(buffer));
    }
    void Paste(){
        for (const auto& t : buffer)
            Insert(t);
    }
    string GetText() const{
        std::string temp;
        for (const auto& t : edit){
            temp.push_back(t);
        }
        return temp;
    }

private:
    std::list<char> edit;
    std::list<char>  buffer;
    _List_iterator<char> it=edit.begin();
    size_t pos=0;
};

void TypeText(Editor& editor, const string& text) {
  for(char c : text) {
    editor.Insert(c);
  }
}

void TestEditing() {
  {
    Editor editor;

    const size_t text_len = 12;
    const size_t first_part_len = 7;
    TypeText(editor, "hello, world");
    for(size_t i = 0; i < text_len; ++i) {
      editor.Left();
    }
    editor.Cut(first_part_len);
    for(size_t i = 0; i < text_len - first_part_len; ++i) {
      editor.Right();
    }
    TypeText(editor, ", ");
    editor.Paste();
    editor.Left();
    editor.Left();
    editor.Cut(3);

    ASSERT_EQUAL(editor.GetText(), "world, hello");
  }
  {
    Editor editor;

    TypeText(editor, "misprnit");
    editor.Left();
    editor.Left();
    editor.Left();
    editor.Cut(1);
    editor.Right();
    editor.Paste();

    ASSERT_EQUAL(editor.GetText(), "misprint");
  }
}

void TestReverse() {
  Editor editor;

  const string text = "esreveR";
  for(char c : text) {
    editor.Insert(c);
    editor.Left();
  }

  ASSERT_EQUAL(editor.GetText(), "Reverse");
}

void TestNoText() {
  Editor editor;
  ASSERT_EQUAL(editor.GetText(), "");

  editor.Left();
  editor.Left();
  editor.Right();
  editor.Right();
  editor.Copy(0);
  editor.Cut(0);
  editor.Paste();

  ASSERT_EQUAL(editor.GetText(), "");
}

void TestEmptyBuffer() {
  Editor editor;

  editor.Paste();
  TypeText(editor, "example");
  editor.Left();
  editor.Left();
  editor.Paste();
  editor.Right();
  editor.Paste();
  editor.Copy(0);
  editor.Paste();
  editor.Left();
  editor.Cut(0);
  editor.Paste();

  ASSERT_EQUAL(editor.GetText(), "example");
}
 void TestCopy(){
    Editor editor;
     TypeText(editor, "example");
     editor.Left();
     editor.Left();
     editor.Left();
     editor.Left();
     editor.Left();
     editor.Left();
     editor.Left();
     editor.Cut(7);
     ASSERT_EQUAL(editor.GetText(), "");
     editor.Paste();
     ASSERT_EQUAL(editor.GetText(), "example");
     editor.Left();
     editor.Copy();
     editor.Paste();
     ASSERT_EQUAL(editor.GetText(), "examplee");


 }
int main() {
  TestRunner tr;
  RUN_TEST(tr, TestEditing);
  RUN_TEST(tr, TestReverse);
  RUN_TEST(tr, TestNoText);
  RUN_TEST(tr, TestEmptyBuffer);
  RUN_TEST(tr, TestCopy);
  return 0;
}