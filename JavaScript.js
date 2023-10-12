const fxn=(input1,input2)=>{
    if(input1=='abcd'){
        if(input2=='abcd'){
            return 'Yes!';
        }
    }
    return 'NO!!'
}

function myCallBackFunction(someArray){
    return someArray*2;
}

const myArray=[1,2,3,4,5];
const newArray=myArray.map(myCallBackFunction);
console.log(newArray);
