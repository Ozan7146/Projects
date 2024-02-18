// import React,{useState} from 'react';
// import { View, Text,TextInput, FlatList, Button,StyleSheet, TouchableOpacity } from 'react-native';




// export default function HomePage() {

//   const [text,setText] = useState('');
//   const [task,setTask] = useState([
//     {text:'Buy Coffee',key:'1'}
//   ])
//   const submitHandler=(text)=>{
//     setTask((prevTask)=>{
//       return [
//         {text:text,key:Math.random().toString()},...prevTask]
//     })
//   }


//   return (
//    <View> 
    
//       <TextInput
//         style ={styles.input}
//         placeholder='Enter To Do Here'
//         onChangeText = {text=>setText(text)}
//       />
//      <TouchableOpacity>
//       <Button
//         onPress={()=>submitHandler(text)}
//         title='Add To Do' color='black'/>
//         {/* style={styles.input} */}
//     </TouchableOpacity>
//    </View>
//   );}


//   const styles =StyleSheet.create({
//     input:{
//         marginBottom:10,
//         paddingHorizontal:8,
//         paddingVertical:6,
//         borderBottomWidth:1,
//         borderBottomColor: '#ddd'

//     }


// })
//-------------------------------------------------------------------------------------------------------------------



import React, { useState} from 'react';
import {StyleSheet, Text, View, FlatList,onPress,Alert,TouchableWithoutFeedback,Keyboard,Button} from 'react-native';
import Header from './components/header';
import ToDoItem from './components/Todoitem';
import AddTodo from  './components/addTodo';


export default function HomePage({navigation}) {
 
  const [todos, setTodos] = useState([
    // {text: 'Kahve iç', key: '1',stateof:false},
    // {text: 'Butonu Sabitle', key: '2',stateof:false},
    // {text: 'flex ögren', key: '3',stateof:false},
  ]);
    
const [deleted, sendDeleted] = useState([])
// const [newtodos,setnewtodos] = useState(todos)




  // const newState = data.map(obj => {
  //   // 👇️ if id equals 2, update country property
  //   if (obj.id === 2) {
  //     return {...obj, country: 'Denmark'};
  //   }
  //   return obj;
  // });

const pressHandler = (item) => {
    
    const newState = todos.map(obj=>{
      //console.log(obj.key)
      if(obj.key==item.key){
        return{...item,stateof:true}
      }
      return obj;
    }) ;
    setTodos(newState);


    // const newState1 = todos.map(obj=>{
    //   //console.log(obj.key)
    //   if(obj.key==item.key){
    //     return{...item,stateof:false}
    //   }
    //   return obj;
    // }) ;
    // setTodos(newState1);
    

  
  //const deletedItem = prevTodos.find((todo) => todo.key === key);
    sendDeleted((prevTodos)=> {
    return [{text:item.text,key:item.key,stateof:false},
            ...prevTodos
    ]
  })
  // console.log(todos.stateof)
    
//     setTodos((prevTodos) => {
//       const underLine = prevTodos.find((todo) => todo.key === item.key);
//       //console.log(...prevTodos)
//       //underLine.style={underline:'line-through'},...prevTodos
//       return[
//       //  <View>         
//       //     <Text style={'line-through'}> underLine </Text>
//       //   </View>

//       ] 
//       /* return prevTodos.filter(todo => todo.key != item.key)      */
//   });
 }
// // console.log({deleted})

const submitHandler=(text)=>{
if(text.length > 3){

setTodos((prevTodos)=>{
  return [
    {text: text,key: Math.random().toString()},
    ...prevTodos
  ];
})
}
  else{
    Alert.alert('Alert!','Must be Longer than 3',[
      {text:'close',onPress:()=> console.log('alert closed')}
    ]);
  }

}

 
  return (
    <TouchableWithoutFeedback onPress={()=>{
      Keyboard.dismiss();
      //console.log('dismissed keyboard');
    }}> 
  
    <View style={styles.container}>
      <Header />
      <View style={styles.content}>
       
        <AddTodo submitHandler={submitHandler}/>
        {/* to form */}
        <View style={styles.otherPage}>
                <Button 
                  color='black'
                  title='Other Page' 
                  onPress={()=>navigation.navigate('SecondPage', {blogpost:deleted})}
             />
          </View>
        <View style={styles.list}>
          
          <FlatList
               
            data={todos}
            renderItem={({item}) =>(
                <ToDoItem item={item} pressHandler={pressHandler}/>
            )}
            />
        
        </View>
      </View>
    </View>
    </TouchableWithoutFeedback>
    
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    flexDirection:'column'
  },
  content: {
    padding: 10,
    backgroundColor: 	'#DCDCDC',
    flex:5,
    
  },
  list: {
    marginTop: 20,
    backgroundColor:'#C0C0C0',
  },
  otherPage: {
      flexDirection:'column',
      //position: 'absolute',
      //alignSelf: 'flex-end',
      //flex:2,
      marginTop:10,
  },
});