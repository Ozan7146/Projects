import { View, Text,FlatList,StyleSheet } from 'react-native'
import React,{useState} from 'react'

export default function SecondPage({route}) {
  // const  {name,id} = route.params;  


 
    console.log(route.params.blogpost)
  return (
    <View style={styles.container}>
        
        <FlatList
        data={route.params.blogpost}
        renderItem={({item}) => (
          <Item title={item.text} />
      )}
        />

    </View>
  )
}
const styles = StyleSheet.create({
  container: {
    flex:1,
    backgroundColor: '#dcdcdc'
  },
  textStyle: {
    fontSize: 16,
    marginVertical: 10,
  },
  item: {
    marginTop: 20,
  },
  title: {
    textAlign: 'center',
    padding: 16,
    marginTop: 5,
    borderColor: 'black',
    borderWidth: 1,
    borderStyle: 'solid',
    borderRadius: 10,
    marginLeft: 20,
    marginRight:20,
  },
});
const Item = ({title}) => (
  <View style={styles.item}>
    <Text style={styles.title}>{title}</Text>
  </View>
);

// import { View, Text } from 'react-native';
// import React, { useState, useEffect } from 'react';

// export default function SecondPage({ route, navigation }) {
//   const { name, id } = route.params;
//   const [newArray, setNewArray] = useState([{ name: '', id: '' }]);

//   Update the state when the component mounts
//   useEffect(() => {
//     setNewArray((prevArray) => [
//       { name: name, id: id },
//       ...prevArray
//     ]);
//   }, [name, id]);

//   console.log(name);
//   console.log(id);

//   return (
//     <View>
//       {/* Displaying the data from the state */}
//       {newArray.map((item, index) => (
//         <Text key={index}>
//           Name: {item.name}, ID: {item.id}
//         </Text>
//       ))}
//     </View>
//   );
// }
