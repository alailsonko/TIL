import { spawn } from 'child_process'

const child = spawn('pwd')

child.stdout.on('data', (data) => {
    console.log(`child stdout:\n${data}`);
})

child.stderr.on('data', (data) => {
    console.log(`child stderr:\n${data}`);
})

child.on('exit', function(code, signal) {
    console.log('child process exited with ' + `code ${code} and signal ${signal}`);
})

const childTwo = spawn('find', ['.', '-type', 'f'])

childTwo.stdout.on('data', (data) => {
    console.log(`childTwo stdout:\n${data}`);
})

const childThree = spawn('wc')

process.stdin.pipe(childThree.stdin)

childThree.stdout.on('data', (data) => {
    console.log(`child stdout:\n${data}`);
})

const find = spawn('find', ['.', '-type', 'f']);
const wc = spawn('wc', ['-l']);

find.stdout.pipe(wc.stdin);

wc.stdout.on('data', (data) => {
  console.log(`Number of files ${data}`);
});