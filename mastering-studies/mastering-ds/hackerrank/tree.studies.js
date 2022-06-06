const util = require('util')


class Tree {
    constructor(value) {
        this.value = value
        this.children = []
    }

    insertChild(value) {
        const newTree = new Tree(value)
        console.log(newTree)
        this.children.push(newTree)
        return newTree
    }
}



const myTree1 = new Tree(1)
const myTree2 = myTree1.insertChild(2)
const myTree4 = myTree1.insertChild(4)
const myTree3 = myTree2.insertChild(3)


console.log('MyTree', util.inspect(myTree1, { showHidden: false, depth: null, colors: false }))
