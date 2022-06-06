const util = require('util')

const sample = [
  '7', ' ', '3', '\n', '1', ' ', '2',
  '\n', '1', ' ', '3', '\n', '1', ' ',
  '4', '\n', '3', ' ', '5', '\n', '3',
  ' ', '6', '\n', '3', ' ', '7', '\n',
  '2', '\n', '2', ' ', '4', '\n', '1',
  '\n', '5', '\n', '3', '\n', '2', ' ',
  '4', ' ', '5'
]

function processData(input) {
  //Enter your code here
  const newArray = []
  let addElem = []
  input.forEach((element, index) => {
    if (element != '\n' && element != ' ') {
      addElem.push(element)
    }
    if (element === '\n' || index === input.length - 1) {
      newArray.push(addElem)
      addElem = []
    }
  });

  // console.log('MyTree',util.inspect(myTree, {showHidden: false, depth: null, colors: false}))

  console.log('input', newArray)
}

processData(sample)