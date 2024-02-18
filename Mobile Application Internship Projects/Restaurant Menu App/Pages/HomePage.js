import { View, Text,Button, StyleSheet,ImageBackground } from 'react-native'
import React from 'react'

export default function HomePage({navigation}) {
  const image = {uri: 'https://media-cdn.tripadvisor.com/media/photo-s/27/9f/45/bc/restaurant.jpg'};  
  return (
    <View style={styles.container}>
      <ImageBackground source={image} resizeMode="cover" style={styles.image}>
        <View style={styles.buttonProp}>
          <Button
            onPress={()=>navigation.navigate("Menu")}
            title="Menu Page"
            color="black"
          />
        </View>
      </ImageBackground>  
    </View>
  )
}

const styles = StyleSheet.create({
  container:{
    flex:1,
    alignContent:'center',
    justifyContent:'center',
   

  },
  image: {
    flex: 1,
    justifyContent: 'center',
  },
  buttonProp:{
     marginLeft:20,
    marginRight:20,
  }

})


