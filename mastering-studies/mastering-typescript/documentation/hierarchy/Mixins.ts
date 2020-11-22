class Sprite {
    name = "" 
    x = 0
    y = 0

    constructor(name: string) {
        this.name = name
    }   
}


// to get started, we need a type which we will use to extend
// other classes from. the main reponsibility is to declare
// that the type being passed in is a class

type Constructor = new (...args: any[]) => {}

// this mixin adds a scale property, with getter and setters 
// for changing it with and encapsulated private property

function Scale<TBase extends Constructor>(Base: TBase) {
    return class scaling extends Base  {
        // Mixins may not declare private/ protected properties,
        // however you can use ES2020 private fields

        _scale = 1

        setScale(scale: number) {
            this._scale = scale
        }

        get scale(): number {
            return this._scale
        }
    }
}

// compose a new class fromt he Sprite class
// with the Mixin Scale applier
const EightBitSprite = Scale(Sprite)

const flappySprite = new EightBitSprite("Bird")
flappySprite.setScale(0.8) 
console.log(flappySprite.scale);
