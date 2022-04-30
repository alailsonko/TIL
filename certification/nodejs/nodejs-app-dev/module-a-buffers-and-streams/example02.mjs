import { createWriteStream } from 'fs'
import { pipeline, Readable, Writable, Transform } from 'stream'
import { promisify } from 'util'


const pipelineAsync = promisify(pipeline)
{
const readablaStream = Readable({
    read: function () {
        this.push('hello1\n')
        this.push('hello2\n')
        this.push('hello3')
        this.push(null)
    }
})

const writableStream = Writable({
    write (chunk, encoding, callback) {
       console.log('msg', chunk.toString())
       callback()
    }
})

await pipelineAsync(
    readablaStream,
    writableStream
)

console.log('done')
}

{


    const readablaStream = Readable({
        read () {
            for (let index = 0; index < 1e5; index++) {
                const element = {
                    id: Date.now() + index,
                    name: 'name-' + index
                };
                const data = JSON.stringify(element)
                this.push(data)
            }
            this.push(null)
        }
    })
    const writableMapToCsv = Transform({
        transform(chunk, encoding, cb) {
     
        
                       const data = JSON.parse(chunk)
            const result = `${data.id},${data.name.toUpperCase()}\n`
              cb(null, result)
          
          
        }
    })
    const setHeader = Transform({
        transform(chunk, encoding, cb) {
            this.count = this.count ?? 0
            if(this.count) {
                return cb(null, chunk)
            }
            this.count++
            cb(null, "id,name\n".concat(chunk))
        }
    })
    await pipelineAsync(
        readablaStream,
        writableMapToCsv,
        setHeader,
        createWriteStream('my.csv')
        // writableStream
    )
}
