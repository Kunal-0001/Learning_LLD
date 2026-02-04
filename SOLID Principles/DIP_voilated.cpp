#include<iostream>
using namespace std;

class MongoDb {
    public:
        void SaveToDB(){
            cout<<"Saved data to mongoDb"<<endl;
        }
};

class SqlDb {
    public:
        void SaveToDB(){
            cout<<"Saved data to sqlDb"<<endl;
        }
};

class UserService {
    private:
        MongoDb mongoDb;
        SqlDb sqlDb;
    public:
        void storeUserToSQL(){
            sqlDb.SaveToDB();
        }

        void storeUserToMongo(){
            mongoDb.SaveToDB();
        }
};

int main(){
UserService* user = new UserService;
user->storeUserToMongo();
user->storeUserToSQL();
return 0;
}