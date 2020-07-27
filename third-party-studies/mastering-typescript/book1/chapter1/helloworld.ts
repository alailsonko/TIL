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
