import EventEmitter from "events";

class MyEmitter extends EventEmitter {}

const myEmitter = new MyEmitter();

myEmitter.on("event", (arg1, arg2) => {
  console.log("an event occurred!", arg1, arg2);
});

myEmitter.emit("event", "an event", "data");


let m = 0

myEmitter.once("event", () => {
    console.log(++m);
})

myEmitter.emit('event');
myEmitter.emit('event');

myEmitter.emit('error', new Error('whoops!'))