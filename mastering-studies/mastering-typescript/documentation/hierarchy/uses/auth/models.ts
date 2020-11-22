import { Manager,  } from "../db/manager";
import { BaseUserManager, AbstractBaseUser } from './base_user'

export class PermissionManager extends Manager {
   
}

export class Permission {

}

export class GroupManager extends Manager {

}

export class Group {

}

export class UserManager extends BaseUserManager {

}

export class PermissionMixin {
      
}

export class AbstractUser {

}

export interface AbstractUser extends AbstractBaseUser, PermissionMixin {

 
}


applyMixins(AbstractUser, [AbstractBaseUser, PermissionMixin]);

function applyMixins(derivedCtor: any, constructors: any[]) {
    constructors.forEach((baseCtor) => {
      Object.getOwnPropertyNames(baseCtor.prototype).forEach((name) => {
        Object.defineProperty(
          derivedCtor.prototype,
          name,
          Object.getOwnPropertyDescriptor(baseCtor.prototype, name)
        );
      });
    });
  }


export class User extends AbstractUser {

}

export class AnonymousUser {

}