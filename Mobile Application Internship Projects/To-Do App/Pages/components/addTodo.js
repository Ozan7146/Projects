import React, {useState} from 'react';
import {StyleSheet, TextInput,View,Text,Button} from 'react-native';

export default function AddTodo({submitHandler}){
    const[text,setText]=useState(' ');

    const changeHandler = (val) =>{
        setText(val);

    }
    return(
    <View>
        <TextInput 
            style = {styles.input}
            placeholder='Add New To Do...'
            onChangeText={changeHandler}
            // onChangeText={(val)=>changeHandler(val)}        
        />
        <Button onPress={()=>submitHandler(text)}
        title='Add To Do' color='black'
        />
        
    </View>
 )} 

const styles =StyleSheet.create({
    input:{
        marginBottom:10,
        paddingHorizontal:8,
        paddingVertical:6,
        borderBottomWidth:1,
        borderBottomColor: 'black',
        marginRight:10

    }


})



   
