console.log('hello world');

var radius = 4;
var area = Math.PI * radius * radius;

area

// radius = 'A string' # static type checking

//Tpe annotation

// primitive type annotation
var nameN: string = "Steve";
nameN
var heigthtCM: number = 182.22;
heigthtCM
var isActive: boolean = true
isActive

// array type annotation
var names: string[] = ['james', 'nick', 'rebeca', 'lily']
names

// function annotation with parameter type annotation and return type annotation
var sayHello: (name: string) => string;

// implementio of sayHello function
sayHello = function (name: string) {
    return 'Hello' + name;
}
const hello1 = sayHello(' one string')
hello1

// object type annotation
var person: { name: string; heightCM: number}

// IMplementtation of a person object
person = {
    name: 'one name',
    heightCM: 437
}
person

// using an intrrface to simplify type annotations

interface Person {
    name: string;
    heightCM: number;
}

var person: Person = {
    name: 'some name',
    heightCM: 4343
}
person

//Arrays

//Typed arrays
interface Monument {
    name: string;
    heightCM: number;
}

// the array is typed uding the monument interface
var monumnets: Monument[] = [];

//  Each item added to the array is checked for type compatibility
monumnets.push({
    name: 'statue of liberty',
    heightCM: 46,
    location: 'USA' // error: this value doe snot exist in type Monument
})

monumnets

monumnets.push({
    name: 'Peter the graet',
    heightCM: 69
})

monumnets

function compareMonumentHeights(a: Monument, b: Monument) {
    if (a.heightCM > b.heightCM) {
        return -1
    }
    if (a.heightCM < b.heightCM) {
        return 1
    }
    return 0

}
// the array.sort method expects a comparer that accepets two Monuments
var monumentsOrderedByHeight = monumnets.sort(compareMonumentHeights);

// get the first element from the array, which is the tallest
var tallestMonumento = monumentsOrderedByHeight[0]

console.log(tallestMonumento.name)


//Enumerations

enum VehicleType {
    PedalCycle,
    MotorCycle,
    car,
    Van,
    Bus,
    Lorry
}

var type = VehicleType.Lorry;
var typeName = VehicleType[type]
typeName

//  Bit Flags

enum DiscFlags {
    None = 0,
    Drive = 1,
    Influence = 2,
    Steadiness = 4,
    Conscientiousness = 8
}

// Using flags
var personally = DiscFlags.Drive | DiscFlags.Conscientiousness;
// Testing flags
//true
var hasD = (personally & DiscFlags.Drive) == DiscFlags.Drive
hasD

var hasI = (personally & DiscFlags.Influence) == DiscFlags.Influence
hasI

var hasS = (personally & DiscFlags.Steadiness) == DiscFlags.Steadiness
hasS

var hasC = (personally & DiscFlags.Conscientiousness) == DiscFlags.Conscientiousness
hasC

// type assertions

interface House {
    bedrooms: number;
    bathrooms: number;
}

interface Mansion {
    bedrooms: number;
    bathrooms: number;
    butlers: number;
}

var avenueRoad: House = {
    bedrooms: 11,
    bathrooms: 10,
    butlers: 1 // error: type not assigned
}

// Errors: Cannot convert house to Mansion
var mansion: Mansion = avenueRoad;
mansion
// Works
var mansion: Mansion = <Mansion>avenueRoad;
mansion

// forced type assertions
var nameN: string = 'Avenue Road'
nameN
// Error: Cannot convert 'string' to 'number'
var bedrooms: number = <Number>nameN;
bedrooms
//Works 
var bedrooms: number = <number> <any> nameN
bedrooms

var counter = 0;

do {
    ++counter;
    counter
} while (counter < 10)
counter

enum Size {
    S,
    M,
    L,
    XL
}

var size = Size.S;
++size;
console.log(Size[size]);

var size = Size.XL;
--size;
console.log(Size[size]);

var size = Size.XL;
++size;
console.log(Size[size]);

// Binary Operators
