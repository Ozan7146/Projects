  import { View, Text, FlatList, Button,Image,StyleSheet, ScrollView } from 'react-native'
  import React, { useState,useEffect } from 'react'
  import datas from '../JSON.json'



  export default function MenuPage({route,navigation}) {
    // const Pageurl= {datas} for API
    const [data,setData]=useState(datas)
    const [showFoods, setShowFoods] = useState(false); 
    const [showDrinks,setShowDrinks] = useState(false);
    const [pressed,setPressed] = useState([])
    
      const Add = (item) => {
        setPressed((prevPressed) => {
          const existingItem = prevPressed.find((a) => a.id === item.id);
          if (existingItem) {
            return prevPressed.map((a) =>
              a.id === item.id ? { ...a, count: Math.min(a.count + 1, 10) } : a
            );
          } else {
            return [...prevPressed, { id: item.id, count: 1,uri:item.url,title:item.title,price:item.price }];
          }
        });
      }
      
      const Delete = (item) => {
        setPressed((prevPressed) => {
          const existingItem = prevPressed.find((a) => a.id === item.id);
          if (existingItem && existingItem.count > 0) {
            return prevPressed.map((a) =>
              a.id === item.id ? { ...a, count: Math.max(a.count - 1, 0) } : a
            );
          } else {
            return prevPressed;
          }
        });
      }
      //console.log(pressed)
      // console.log(pressed)
    const printCount = (itemId) =>{
      const item = pressed.find((a) => a.id === itemId);
      return item ? item.count : 0;
    }

    const printPrice = (itemId) =>{
      const item = pressed.find((a) => a.id === itemId);
      return item ? (item.price*item.count) : 0;
    }

    const toggleFoods = () => {
        setShowFoods(true);
        setShowDrinks(false); 
    };
    const toggleDrinks = () =>{  
        setShowDrinks(true);  
        setShowFoods(false);
    };

    const renderItem = ({ item }) => {
      //console.log(item.id);  
      return (      
        
        <View style={styles.renderContainer}>
          <View>
            <Image source={{ uri: item.url }} style={{ width: 100, height: 100,flex:1 }} />
          </View>
          <View style={{ flex:3,flexDirection:'row',justifyContent:'center' }}>
            <View style={{ flex:2,flexDirection:'row',justifyContent:'center',alignItems:'center'}}>
              <Text style={{fontWeight: 'bold'}}>{item.title}</Text>
            </View>
            <View style={styles.deleteContainer}>  
              <Button 
               title="-"
               color='black'
               onPress={() => Delete(item)}
              />
            </View>
            <View style={{justifyContent:'center',alignItems:'center',}}>
              <Text>{printCount(item.id)}</Text>
              <Text>{printPrice(item.id)}TL</Text>
            </View>
            <View style={styles.addContainer}>
              <Button 
                title="+"
                color='black'
                onPress={()=>Add(item)}/>
            </View>
          </View>
        </View>  
          
      );
  }
    return (
      <View style={styles.container}>   
        <View style={{marginLeft:20,marginRight:20,marginTop:10}}>        
          <Button 
            title='FOODS'
            color='black'
            onPress={toggleFoods}
          />
        </View>
        <View style={{marginLeft:20,marginRight:20,marginTop:10}}>    
            <Button 
            title='DRINKS'
            color='black'
            onPress={toggleDrinks} />  
        </View>
        <View style={{marginLeft:20,marginRight:20,marginTop:10}}>
          <Button
            title='TOTAL'
            color='black'
            onPress={()=>navigation.navigate("Total",{blogpost:pressed})}
          />
        </View>
        <View style={styles.foodAndDrinkContainer}>   
            {(!showDrinks && showFoods) && (<FlatList style={styles.flatContainer} data={datas.foods} renderItem={renderItem} />)} 
            {(showDrinks && !showFoods) && (<FlatList style={styles.flatContainer} data={datas.drinks} renderItem={renderItem} keyExtractor={renderItem => renderItem.id}/>)}  
        </View> 
      </View>


    )
  }
 
  const styles=StyleSheet.create({
    container:{
      backgroundColor:'#dcdcdc',
      flex:1,
      
    },
    foodAndDrinkContainer:{

      margin:20,
      borderColor: 'black',
      borderWidth: 2,
      borderStyle: 'solid',
      borderRadius: 10,
      marginTop:10,
    },

    renderContainer:{
      
      flexDirection:'row',
      borderColor: 'black',
      borderWidth: 1,
      borderStyle: 'solid',
      borderRadius: 10,
      margin:10
      
    },
    flatContainer:{
      margin:10
    },
    addContainer:{
      flex:1,
      justifyContent:'center',
      alignItems:'center',
    },
    deleteContainer:{      
      flex:1,
      justifyContent:'center',
      alignItems:'center',
    }
  })



    // useEffect(()=>{
    //   fetch(Pageurl)
    //   .then((response)=>response.json()
    //   .then((dat)=>setData(dat)))
    //   .catch((error)=>console.error(error))
    //   .finally(()=>setLoading(false))
    // },[])


        // const Delete = (item) => {  
      
    //   if(count  > 1){
    //      setCount(count-1)
    //       const newData = { id, count };
    //       setPressed((prevDataList) => [...prevDataList, newData]);
    //       setPressed(item.id,{count})
    //   }
    // };
  
    // const Add = (item) => {
    //   if(count <10){
    //     setCount(count+1);
    //     setPressed(item.id,{count})
    //     // console.log(item.id)
    //   } 
    // };   
    // console.log(pressed)
    //  console.log(count)


    
    // const Add = (item) =>{
    //   pressed.find((a)=> 
    //     a.id==item.id?
    //     setPressed({...a,count: Math.max(a.count+1,10)})
    //     :
    //     setPressed({...a,id:item.id,count:1}));
    //     //setPressed(exists1)
    //     }
         

      
    // const Delete = (item) =>{
    //   pressed.find((a)=> 
    //     a.id==item.id?
    //     setPressed({...a,count: Math.max(a.count-1,0)})
    //     :
    //     setPressed(a));
        
    //     }