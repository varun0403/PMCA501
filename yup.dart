import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;
class DataScreen extends StatefulWidget{
  const DataScreen({super.key});
  State<DataScreen> createState()=> _DatascreenState();
}
class _DatascreenState extends State<DataScreen>{
  String displayText="loadingg.....";
  Future<void> fetchData() async{
    final response=await http.get(Uri.parse('https://jsonplaceholder.typicode.com/todos/2'));
    if(response.statusCode==200){
      setState(() {
        displayText=response.body;
      });
    }else{
      setState(() {
        displayText="failed to load data";
      });
    }
  }
  void initState(){
    super.initState();
    fetchData();
  }
  Widget build(BuildContext context){
    return Scaffold(
      appBar: AppBar(title:Text("basic api app")),
      body:Center(
        child: Text(displayText),
      )
    );
  }
}
