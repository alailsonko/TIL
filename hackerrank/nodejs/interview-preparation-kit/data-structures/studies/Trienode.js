module.exports = class TrieNode {
    constructor(char) {
        this.children = []
        for(let i = 0; i < 26; i++) {
            this.children[i] = null
        }
        this.isEndWord = false
        this.char = char
    }

    markAsLeaf() {
        this.isEndWord = true
    }

    unMarkAsLeaf() {
        this.isEndWord = false
    }
}