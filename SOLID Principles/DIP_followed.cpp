#include<iostream>
using namespace std;
 
class Database {
    public:
        virtual void SaveToDb() = 0;
};

class SaveToMongo : public Database {
    public:
        void SaveToDb() override {
            cout<<"Saved the data into MongoDb"<<endl;
        }
};

class SaveToSQL : public Database {
    public:
        void SaveToDb() override {
            cout<<"Saved he data into SQL Db"<<endl;
        }
};

class UserService{
    private:
        Database* db;
    public:
        UserService(Database* db){
            this->db = db;
        }
        void StoreUser(){
            db->SaveToDb();
        }
};

int main(){
SaveToMongo* mongo = new SaveToMongo();
SaveToSQL* sql = new SaveToSQL();

UserService* user1 = new UserService(mongo);
user1->StoreUser();

UserService* user2 = new UserService(sql);
user2->StoreUser();
return 0;
}