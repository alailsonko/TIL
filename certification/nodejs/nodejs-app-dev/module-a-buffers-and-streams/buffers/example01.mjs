import { Buffer } from "buffer";

const buf1 = Buffer.alloc(10);

console.log("buf1:", buf1);

const buf2 = Buffer.alloc(10, 1);

console.log("buf2:", buf2);

const buf3 = Buffer.allocUnsafe(10);

console.log("buf3:", buf3);

const buf4 = Buffer.from([1, 2, 3]);

console.log("buf4:", buf4);

const buf5 = Buffer.from([257, 257.5, -255, '1']);

console.log("buf5:", buf5);

const buf6 = Buffer.from('test', 'latin1');

console.log("buf6:", buf6);

console.log('------------------------------------------')

const buf7 = Buffer.from([1,2,3,4]);

const uint32array = new Uint32Array(buf7);

console.log("uint32array:", uint32array);

const  buf8 = Buffer.from('hello', 'utf16le')

const uint16array1 = new Uint16Array(
    buf8.buffer,
    buf8.byteOffset,
    buf8.length /  Uint16Array.BYTES_PER_ELEMENT
);

console.log("uint16array1:", uint16array1);

const arr = new Uint16Array(2)

arr[0] = 5000
arr[1] = 4000

const buf9 = Buffer.from(arr)

const buf10 = Buffer.from(arr.buffer)

console.log('buf9:', buf9);
console.log('buf10:', buf10);

arr[1] = 6000

console.log('buf9:', buf9);
console.log('buf10:', buf10);

const arr1 = new Uint16Array(20)

const buf11 = Buffer.from(arr1.buffer, 0, 16)

arr1[0] = 5000

console.log('buf11:', buf11);
console.log('buf11:', buf11.length);