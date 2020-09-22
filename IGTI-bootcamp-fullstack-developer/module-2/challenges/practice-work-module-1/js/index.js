window.addEventListener('load', start)
window.addEventListener('mousemove', start)

 function start(){
    console.log('loaded')
   range()
   changeSquareColor()
}

const inputObjectsID = [ 
    { id: 'red', idInput: 'red-input', value: null},
    { id: 'green', idInput: 'green-input',  value: null},
    { id: 'blue', idInput: 'blue-input',  value: null}
        ]

function range(){
    for(let i of inputObjectsID) {
      var inputRange =  document.getElementById(i.id).value

      i.value = inputRange

      document.getElementById(i.idInput).value = inputRange

    }
}
function changeSquareColor() {
  document.getElementById('square').style.backgroundColor = `rgb(${inputObjectsID[0].value}, ${inputObjectsID[1].value}, ${inputObjectsID[2].value})`
}