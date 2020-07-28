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

var num = 5 + 1
num

var str = 5 + '1'
str

// unary plus and minus operators

var str: string = '5'
str

// 5: number
var num = +str;
num

// -5: number
var negative = -str;

// Bitwise Operators

/**
 * & | ^ << >> <<< >>> ~
 */

// Logical Operators

// NOT operator

var truthyString = 'Truthy string'
var falseyString: string;
truthyString
falseyString
// false, it checks the string but inverts the truth
var invertedTest = ! truthyString;
invertedTest
// true, the string is not undefined or empty
var truthyStest = !! truthyString;
truthyStest
// false, the string is empty
var falseyTest = !! falseyString
falseyTest

// shorthand boolean test

var myProperty;

if (myProperty) {
   // Reaching this location means that...
   // myProperty is not null
   // myPropperty is not undefined
   // myProperty is not boolean false
   // myProperty is not an empty string
   // myProperty is not the number 0
   // myProperty is not NaN
}

// AND operator
    // longhand
if (console) {
    console.log('Console available')
}
    // shorthand
console && console.log('console available');

var player1 = 'Martin'

// player2 is only defined if player is defined
var player2 = player1 && 'Dan'

// 'Dan'
console.log(player2);


// OR operator

// Empty string are falsey
var errorMessages = '';

// result is 'Saved OK'
var result = errorMessages || 'Saved OK'
result

// filled string are truthy
errorMessages = 'Error Detected'

// result is 'Error Detected'
result = errorMessages || 'Saved OK'
result

var undefinedLogger;

// if the logger isn't initialized, 
// subtitle it for the result of the right-hannd expression
var logger = undefinedLogger || { log: function(msg: string ){ console.log(msg)}}

logger.log('message')

// short circuit evaluation
interface Caravan {
    rooms: number;
}
var caravan: Caravan;


if (caravan && caravan.rooms > 5) {
    //...
}

// Conditional Operator

var isValid = true;

// longhand equivalent
if (isValid) {
    message = 'Okay'
} else {
    message = 'Failed'
}

//Conditional operator
var message = isValid ? 'Okay' : 'Failed'
message

// Functions

  //  function type annotations

  function getAverage1(a: number, b: number, c: number): string {
      var total = a + b + c;
      var average = total / 3;
      return 'The average is ' + average
  }

var result1 = getAverage1(4, 3, 10)
console.log(result1)


// Optional Parameters

function getAverage2(a: number, b: number, c?: number): string {
    var total = a;
    var count = 1;

    total += b
    count++

    if ( typeof c != 'undefined') {
        total +=c;
        count++;
    }

    var average = total / count;
    return 'The average is ' + average
}

var result2 = getAverage2(4, 6)
result2


// default parameters
function concatenate(
    items: string[], 
    separator = ',', 
    beginAt = 0, 
    endAt = items.length 
    ) {
     var result = '';

     for (var i = beginAt; i < endAt; i++) {
         result += items[i];
         if (i < (endAt - 1)) {
             result += separator
         }
     }
     return result
}

var items  = ['A', 'B', 'C'];

// 'A,B,C'
var result = concatenate(items)
result
// 'B-C'
var partialResult = concatenate(items, '-', 1)
partialResult

// Rest Parameters

function getAverage3(...a: number[]): string {
    var total = 0;
    var count = 0;

    for (var i = 0; i < a.length; i++) {
        total += a[i]
        count++
    }

    var average = total / count;
    return 'The average is ' + average
}

var result3 = getAverage3(2, 4, 6, 8, 10)
result3

// Overloads
function getAverage4(a: string, b: string, c: string);
function getAverage4(a: number, b: number, c: number);
// implementation signature
function getAverage4(a: any, b: any, c: any): string {
    var total = parseInt(a, 10) + parseInt(b, 10) + parseInt(c, 10)
    var average = total / 3
    return 'the average is ' + average 
}

var result4 = getAverage4(4, 3, 8)

result4

// specialized overload signatures

class HandlerFactory {
    getHandler(type: 'Random'): RandomHandler;
    getHandler(type: 'Reversed'): ReversedHandler;
    getHandler(type: string): Handler; // non specialized signature
    getHandler(type: string): Handler { //implementation signature
       switch (type) {
           case 'Random':
               return new RandomHandler();
           case 'Reversed':
               return new ReversedHandler();
            default:
                return new Handler();
       }
    }
}
var ScoleLosingExample = {
    text: "Property from lexical scope",
    run: function () {
        setTimeout(() => {
            console.log(this.text);
            
        }, 5000)
    }
}
ScoleLosingExample.run()

// interfaces

interface Point {
    // Properties
    x: number;
    y: number;
}

interface Passenger {
    // Properties
    name: string;
}

interface Vehicle {
    //constructor 
    new() : Vehicle;
    // Properties
    currentLocation: Point;
    // Methods 
    travelTo(point: Point);
    addPassenger(passenger: Passenger);
    removePassenger(passenger: Passenger)
}

interface NodeList {
    length: number;
    item(index: number): Node;
    [index: number]: Node;
}

interface NodeList {
    onclick: (event: MouseEvent) => any;
}

var nodeList = document.getElementsByTagName('div');

nodeList.onclick = function (event: MouseEvent) {
    console.log('Clicked');
}