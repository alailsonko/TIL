// const stdin = process.stdin
// .on('data', msg => console.log('input terminal', msg.toString()))

// const stdout = process.stdout.on('data', msg => console.log('output terminal', msg.toString()))

// stdin.pipe(stdout)
// .on('error')
// .on('end')
// .on('close')

// import http from 'http'

// import { readFileSync, createReadStream } from 'fs'
 
// node -e "process.stdout.write(crypto.randomBytes(1e9))" > big.file
// http.createServer((req, res) => {
//    const file = readFileSync('big.file')
//    res.write(file)
//    res.end()
//     createReadStream('big.file')
//     .pipe(res)


// }).listen(3000, () => console.log('server started'))

// import net from 'net'

// net.createServer(socket => socket.pipe(process.stdout)).listen(1338)

// node -e "process.stdin.pipe(require('net").connect(1338)

