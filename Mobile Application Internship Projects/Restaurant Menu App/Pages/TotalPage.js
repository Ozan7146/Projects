import { View, Text, FlatList, StyleSheet, Image, Button } from 'react-native';
import React, { useState } from 'react';

export default function TotalPage({ route }) {
  const [datas, setDatas] = useState(route.params.blogpost);
  const[price,setPrice]=useState([])
  //const[buyButton,setBuyButton]=useState(false)
  const printCount = (itemId) => {
    const item = datas.find((a) => a.id === itemId);
    return item ? item.count : 0;
  };
  const printPrice = (itemId) =>{
    const item = datas.find((a) => a.id === itemId);
    // setPrice((item.price*item.count)) 
    return item ? (item,item.price*item.count) : 0;
  }
  const printTotal = () => {
    const x = (datas.reduce((a,v) =>  a = a + (v.price*v.count) , 0 ))
    return x
  }

  const Add = (itemId) => {
    setDatas((prevDatas) =>
      prevDatas.map((item) =>
        item.id === itemId ? { ...item, count: Math.min(item.count + 1, 10) } : item
      ),
    );
  };

  const Delete = (itemId) => {
    setDatas((prevDatas) =>
      prevDatas.map((item) =>
      item.id === itemId ? { ...item, count:  Math.max(item.count - 1, 0) } : item
      ),
    );
    setDatas((prevDatas) => prevDatas.filter((item) => item.count > 0));

  };

  const renderItem = ({ item }) => {
    return (
      <View style={styles.renderContainer}>
        <View>
          <Image source={{ uri: item.uri }} style={{ width: 100, height: 100, flex: 1 }} />
        </View>
        <View style={{ flex: 3, flexDirection: 'row', justifyContent: 'center' }}>
          <View style={{ flex: 2, flexDirection: 'row', justifyContent: 'center', alignItems: 'center' }}>
            <Text style={{ fontWeight: 'bold' }}>{item.title}</Text>
          </View>
          <View style={styles.deleteContainer}>
            <Button title="-" color='black' onPress={() => Delete(item.id,item)} />
          </View>
          <View style={{ justifyContent: 'center', alignItems: 'center' }}>
            <Text>{printCount(item.id)}</Text>
            <Text>{printPrice(item.id)}TL</Text>
          </View>
          <View style={styles.addContainer}>
            <Button title="+" color='black' onPress={() => Add(item.id)} />
          </View>
        </View>
      </View>
    );
  };

  return (
    <View style={{flex:1,flexDirection:'column'}}>
      <View style={{flex:4}}>
      <FlatList
        data={datas}
        renderItem={renderItem}
      />
      </View>
      <View style={{flex:1,justifyContent:'center',alignItems:'center'}}>
        <Text style={{fontWeight: 'bold'}}>Total Price:</Text>
        <Text style={{fontWeight: 'bold'}}>-------------------------</Text>
        <Text style={{fontWeight: 'bold'}}>{printTotal()}TL</Text>
      </View>
      
    </View>
  );
}

const styles = StyleSheet.create({
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
});
