import { Blob, Buffer } from 'buffer';
import { setTimeout as delay } from 'timers/promises'

const obj = {
    hello: 'world',
}

const blob = new Blob([JSON.stringify(obj, null, 2)], {
    type: 'application/json',
})

console.log('blob:', blob);

function typedArrayToURl(typedArray, mimeType) { 
  return URL.createObjectURL(new Blob([typedArray.buffer], { type: mimeType }));
}

const bytes = new Uint8Array(59)

for (let i = 0; i < bytes.length; i++) {
  bytes[i] = 32 + i
}

const url = typedArrayToURl(bytes, 'text/plain');


console.log('url:', url);


const blob1 = new Blob(['hello there'])

const mc1 = new MessageChannel()
const mc2 = new MessageChannel()

mc1.port1.onmessage = async ({data}) => {
    console.log('mc1:', await data.arrayBuffer());
    mc1.port1.close()
}

mc2.port1.onmessage = async ({data}) => { 
    await delay(1000)
    console.log('mc2:', await data.arrayBuffer());
    mc2.port1.close()
}



mc1.port2.postMessage(blob1)
mc2.port2.postMessage(blob1)

blob1.text().then(console.log)