import React, {useState} from 'react'
function UseStateComponent() {
    const [arr, setArr] = useState<number[]>([])
    const [name, setName] = useState<string | null>(null)
    return (
        <div>
            <div>
                <button type="button" 
                onClick={() => setArr(
                    [
                        ...arr, 
                        arr.length + 1]
                )}>
                    Add To array
                </button>
                {JSON.stringify(arr)}
            </div>
            <div>
                <button type="button" 
                onClick={() => setName('Alailson')}>
                    set name
                </button>
                {JSON.stringify(name)}
            </div>
        </div>
    )
}

export default UseStateComponent