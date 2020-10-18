/**
 * genereic type in functions
 * 
 */

function id(arg: number): number {
    return arg;
}

function id1(arg: any): any {
    return arg
}

function id2<T>(arg: T): T {
    console.log(arg.length)
    return arg
 }
 
function id3<T>(arg: T[]): T[] {
    console.log(arg.length)
    return arg
 }

let output = id2<string>("myString")
let output1 = id2<string>("myString")
let output2 = id2<number>(2)

let output3 = id3<number>(2)


// option 3

function identity<T>(arg: T): T {
    return arg;
}

let myIdentity: <T>(arg: T) => T = identity;

let myIdentity1: <U>(arg: U) => U = identity;

let myIdentity2:  { <U>(arg: U): U } = identity;


// option 4

interface GenericIdentityFn {
    <T>(arg: T): T;
}

function identity4<T>(arg: T): T {
    return arg;
}

let myIdentity3: GenericIdentityFn = identity4


// option5

interface GenericIdentityFn1<T> {
    (arg: T): T;
}

function identity5<T>(arg: T): T {
    return arg;
}

let myIdentity4: GenericIdentityFn1<number> = identity5

/**
 * 
 * generic classes
 * 
 */


 class GenericNumber<T> {
     zeroValue: T;
     add: (x: T, y: T) => T;
 }

let myGenericNumber = new GenericNumber<number>()
myGenericNumber.zeroValue = 0;
myGenericNumber.add = function(x, y) { return x + y}


// @strict-false
class GenericNumber1<T> {
    zeroValue: T;
    add: (x: T, y: T) => T;
}
// ---cut---
let stringNumeric = new GenericNumber1<string>()
stringNumeric.zeroValue = ""
stringNumeric.add = function(x, y) { return x + y}

console.log(stringNumeric.add(stringNumeric.zeroValue, "test"));


/**
 * 
 * Generic constraints
 * 
*/

interface Lengthwise {
    length: number;
}

function logId<T extends Lengthwise>(arg: T): T {
    console.log(arg.length)
     console.log(arg);
     
    return arg
}

logId({ length: 10, value: 3 })

/**
 * 
 * Using type parameters in generics constraints
 * 
 */

 function getProperty<T, K extends keyof T>(obj: T, key: K) {
     return obj[key]
 }

let x = { a: 1, b: 2, c: 3, d: 4};

getProperty(x, "a")
getProperty(x, "m")



/**
 * 
 * using class types in generics
 * 
 */

 function create<T>(c: { new (): T }): T {
     return new c()
 }



 class BeeKeeper {
    hasMask: boolean;
  }
  
  class ZooKeeper {
    nametag: string;
  }
  
  class Animal {
    numLegs: number;
  }
  
  class Bee extends Animal {
    keeper: BeeKeeper;
  }
  
  class Lion extends Animal {
    keeper: ZooKeeper;
  }
  
  function createInstance<A extends Animal>(c: new () => A): A {
    return new c();
  }
  
  createInstance(Lion).keeper.nametag;
  createInstance(Bee).keeper.hasMask;
