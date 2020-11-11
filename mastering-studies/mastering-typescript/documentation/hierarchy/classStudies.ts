// classes 

  // simple class based

  class Greeter {
      greeting: string

      constructor(message: string) {
          this.greeting = message
      }

      greet() {
          return "Hello, " + this.greeting
      }
  }

  let greeter = new Greeter("world")

  console.log(greeter.greet());
  

  // Inheritance 

   // object-oriented patterns

// class Animal {
//     move(distanceInMeters: number = 0) {
//         console.log(`Animal moved ${distanceInMeters}m.`);
//     }
// }

// class Dog extends Animal {
//     bark(){
//         console.log("woof woof");
        
//     }
// }

// const dog = new Dog()
// dog.bark()
// dog.move(10) 
// dog.bark()

class Animal {
    name: string
    constructor(theName: string) {
        this.name = theName
    }

    move(distanceInMeters: number = 0) {
        console.log(`${this.name} moved ${distanceInMeters}m.`);
    }
}

class Snake extends Animal {
    constructor(name: string) {
        super(name)
    }
    move(distanceInMeters: number = 5) {
        console.log("slithering...")
        super.move(distanceInMeters)
    }
}

class Horse extends Animal {
    constructor(name: string) {
        super(name)
    }
    move(distanceInMeters: number = 45) {
        console.log("Galloping..");
        super.move(distanceInMeters)
    }
}

let sam = new Snake("sammy the pythong")
let tom: Animal = new Horse("tom the pythong")

sam.move()
tom.move(34)

// public, private, and protected modifiers

   // public by default

   class Animal1 {
       public name: string
       public constructor(theName: string) {
        this.name = theName
    }

    public move(distanceInMeters: number) {
        console.log(`${this.name} moved ${distanceInMeters}`);
    }
   }

// ecmascript private fields

class Animal2 {
    #name: string
    constructor(theName: string) {
        this.#name = theName;
    }
}


// new Animal("cat").#name

// undestanding typescript private

class Animal4 {
    private name: string

    constructor(theName: string) {
        this.name = theName;
    }
}

new Animal("cat").name

class Animal5 {
    private name: string
    constructor(theName: string) {
        this.name = theName;
    }
}

class Rhino extends Animal5 {
    constructor() {
        super("rhino")
    }
}

class Employee {
    private name: string
    constructor(theName: string) {
        this.name = theName;
    }
}

let animal = new Animal5("Goat") 
let rhino = new Rhino() 
let employee = new Employee("bob")  

animal = rhino
// animal = employee

    // understanding protected

class Person {
    protected name: string
    constructor(name: string) {
        this.name = name
    }
}

class Employee1 extends Person {
    private department: string  
    constructor(name: string, department: string) {
        super(name) 
        this.department = department 
    }

    public getElevatorPitch() {
        return `Hello, my name is ${this.name} and i work in ${this.department}`
    }
}

let howard  = new Employee1("howard", "sales")
console.log(howard.getElevatorPitch());
// console.log(howard.name);  

class Person1 {
 protected name: string
 protected constructor(theName: string) {
     this.name  = theName
 }
}

// employee  can exnted person
 class Employee3 extends  Person1 {
     private department: string 

     constructor(name: string, department: string) {
         super(name) 
         this.department = department
     }

     public getElevatorPitch() {
         return `Hello, my name is ${this.name} and i work in ${this.department}`
     }
 }


let howard1 = new Employee3("howard", "Sales")
// let john = new Person1("john")


//  readonly  modifiers

class Octopus {
    readonly name: string
    readonly numberOfLegs: number = 8

    constructor(theName: string) {
        this.name = theName
    }
}

let dad = new Octopus("man with 8 strong legs")
// dad.name = "man witth the 3 piece suit"


// parameter properties 
class Octopus1 {
    readonly numberOfLegs: number = 8
    constructor(readonly name: string){}
}

let dad1 = new Octopus1("man with 8 strong legs")
console.log(dad1.name);



// Accessors

class Employee6 {
    fullname: string
}

let emp = new Employee6() 
emp.fullname = "bob smith"

if(emp.fullname) {
    console.log(emp.fullname);
}

const fullNameMaxLength = 10  

class Emp1 {
    private _fullName: string = "";

    get fullname(): string {
        return this._fullName
    }

    set fullname(newName: string) {
        if (newName && newName.length > fullNameMaxLength) {
            throw new Error("fullname ha a amx length of " + fullNameMaxLength)
        }

        this._fullName = newName
    }
}

let emp3 = new Emp1() 
emp3.fullname = "bob smith"

if(emp3.fullname) {
    console.log(emp3.fullname);
    
}

// static properties


class Grid {
    static origin = { x: 0, y: 0}

    calcDistFromOrigin(point: { x: number, y: number}) {
        let xDist = point.x - Grid.origin.x
        let yDIst = point.y - Grid.origin.y
        return Math.sqrt(xDist * xDist + yDIst * yDIst) / this.scale
    }

    constructor(public scale: number) {
    }
}

let grid1 = new Grid(1.0)
console.log(grid1);

let grid2 = new Grid(5.0)
console.log(grid2);

console.log(grid1.calcDistFromOrigin({ x: 10.0, y: 10.0 }));
console.log(grid2.calcDistFromOrigin({ x: 10.0, y: 10.0 }));


// Abstract Classes  

abstract class Animal8 {
    abstract makeSound(): void 
    move(): void {
        console.log("roaming the earth...");
    }
}



abstract class Department {
    constructor(public name: string) {

    }

    printName(): void {
        console.log("Department name: " + this.name);
    }

    abstract printMeeting():void

}

class AccountingDepartment extends Department {
    constructor() {
        super("accounting and auditing")
    }

    printMeeting(): void {
        console.log("the accouting department meets each monday at 10am");
    }

    generateReport(): void {
        console.log("generating accounting reports...");
    }
}

let dep = typeof Department
// dep = new Department()   
// dep = new AccountingDepartment() 
// dep.printMeeting()
// dep.printName()
// dep.generateReport()


// advanced techniques

   // constructor functions
class Gr {
    greeting: string

    constructor(message: string) {
        this.greeting = message
    }

    greet() {
        return "hello " + this.greeting
    }
}

let gr: Greeter
gr = new Greeter("world")
console.log(gr.greet());

class Greeter9 {
    static standardGreeting = "Hello, there"
    greeting: string 
    greet() {
        
    }
}