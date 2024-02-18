import React from 'react';
import {StyleSheet, Text , TouchableOpacity,View} from 'react-native';


export default function ToDoItem({item,pressHandler}){
    
    
    press = (item) =>{
        if(item.stateof==false)
            {
               return pressHandler(item)
            }
    }
    
    
    
    //console.log(item.stateof)
    return(
        <TouchableOpacity onPress={()=> pressHandler(item) }>
            <View style={styles.items}>
                {item.stateof
                    ?<Text style={styles.line}>{item.text}</Text>
                    :<Text>{item.text}</Text>
                }
            </View>
         </TouchableOpacity> 

    )}

const styles = StyleSheet.create({
    items:{
        padding:16,
        marginTop:16,
        borderColor:'#bbb',
        borderWidth:1,
        borderStyle: 'dashed',
        borderRadius: 10,

    },
    line:{
        textDecorationLine:'line-through',
        color:'black',
    }
})

