#include<iostream>
#include <vector>
#include <string> 
#include <fstream>
using namespace std;

class DocumentElement {
    public:
        virtual string render() = 0;
};

class TextElement : public DocumentElement{
    private:
        string text;
    public:
        TextElement(string text) {
            this->text = text;
        }

        string render(){
            return text; 
        }
};

class ImageElement : public DocumentElement{
    private:
        string imagePath;
    public:
        ImageElement(string imagePath){
            this->imagePath=imagePath;
        }

        string render(){
            return imagePath;
        }
};

class NewLineElement : public DocumentElement {
    public:
        string render(){
            return "\n";
        }
};

class TabSpaceElement : public DocumentElement {
    public:
        string render(){
            return "\t";
        }
};

class Document {
    private:
        vector<DocumentElement*> elements;
    public:
        void addElement(DocumentElement* element){
            elements.push_back(element);
        }

        string render(){
            string result;
            for(auto element : elements){
                result+=element->render();
            }
            return result;
        }
};

class Persistence {
public:
    virtual void save(string data) = 0;
};

class FileStorage : public Persistence {
public:
    void save(string data) override {
        ofstream outFile("document.txt");
        if (outFile) {
            outFile << data;
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        } else {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }
};

class DBStorage : public Persistence {
    public:
        void save(string data) override {
            cout<<" The data "<<data<<" has been stored to db"<<endl;
        }
};

class DocumentEditor{
    private:
        Document* doc;
        Persistence* db;
        string renderedDocument;
    public:
        DocumentEditor(Document* doc, Persistence* db){
            this->doc=doc;
            this->db=db;
        }

        void addText(string data){
            doc->addElement(new TextElement(data));
        }

        void addImage(string imagePath){
            doc->addElement(new ImageElement(imagePath));
        }

        void addNewLine(){
            doc->addElement(new NewLineElement());
        }

        void addTabSpace(){
            doc->addElement(new TabSpaceElement());
        }

        string renderDocument(){
            if(renderedDocument.empty()){
                renderedDocument = doc->render();
            }
            return renderedDocument;
        }

        void save(){
            db->save(renderDocument());
        }
};

int main(){
    Document* doc = new Document();
    Persistence* storage = new FileStorage();
    DocumentEditor* editor = new DocumentEditor(doc, storage);
    editor->addText("Hello, World!");
    editor->addNewLine();
    editor->addImage("picture.jpg");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("This line is gettig printed after a tab");

    cout<<editor->renderDocument()<<endl;

    editor->save();

return 0;
}