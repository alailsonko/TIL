
 
let UserCredentials = []

class AbstractUser {
   public _email: string
   public _password: string
   public _username?: string
   public _first_name?: string
   public _last_name?: string


  constructor(
        email: string,
        password: string,    
        username?: string, 
        first_name?: string, 
        last_name?: string,

        ){
            this._username = username;
            this._first_name = first_name;
            this._last_name = last_name;
            this._password = password;
            this._email = email;
        }

        saveUser() {
          const UserModel = {
           username: this._username,
           first_name: this._first_name,
           last_name: this._last_name,
           password: this._password,
           email: this._email
           }
           UserCredentials.push(UserModel)
        }

        getUser(): object {
            return UserCredentials
        }

}

class User extends AbstractUser {
}

let user = new User('user@example.com', 'password');

user.saveUser()
console.log(user.getUser())
console.log(UserCredentials)