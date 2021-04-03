const util = require('util');
class Node {
	constructor(char) {
		this.char = char
		this.children = []
		this.ends = 0
	}

	findOrCreateChild(char) {
		this.ends++
		return this.findChild(char) || this.createChild(char)
	}

	createChild(char) {
		const newChild = new Node(char)
		this.children.push(newChild)
		console.log('newChild',newChild)
		return newChild
	}

	findChild (char) {
		console.log('find',this.children.find(node => node.char === char))
		console.log('char',char)
		return this.children.find(node => node.char === char)
	}
}

class Trie {
	constructor() {
          this.root = new Node(null)
	}
	add(word) {
		let currentNode = this.root
		for (const char of word) {
			// console.log(char)
			currentNode = currentNode.findOrCreateChild(char)
			console.log('Node',util.inspect(currentNode, { depth: null, showHidden: false}))

		}
		currentNode.findOrCreateChild(Trie.END_CHARACTHER)
	}

	getMatchCount(partial) {
		let currentNode = this.root
		for(const char of partial) {
			const childNode = currentNode.findChild(char)
			if(!childNode) return 0;
			console.log('childNode',childNode)
			currentNode = childNode
		}
		return currentNode.ends
	}
}


Trie.END_CHARACTHER = "*"

function contacts(queries) {
	const store = new Trie();
	const output = []
	for (const [command, string] of queries) {
		if(command === 'add') {
		store.add(string)
		} else {
			console.log(output)
			output.push(store.getMatchCount(string))
		}
	}

	return output
}

const queries = [
	['add', 'abc'], 
	['add', 'abcd'], 
	['find', 'abc'],
	['find', 'abcd'],
	['find', 'hak'] 
]


contacts(queries)

