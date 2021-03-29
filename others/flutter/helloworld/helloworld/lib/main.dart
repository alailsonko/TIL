import 'package:flutter/material.dart';
import './question.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatefulWidget {
  @override
  State<StatefulWidget> createState() {
    return _MyAppState();
  }
}

class _MyAppState extends State<MyApp> {
  var _questionIndex = 0;
  void _answerQuestion() {
    setState(() {
      if (_questionIndex == 1) {
        _questionIndex = 0;
        return;
      }
      _questionIndex = _questionIndex + 1;
    });
    print(_questionIndex);
  }

  @override
  Widget build(BuildContext ctx) {
    var questions = [
      'What\' is ur fav color?',
      'What\'s ur fav animal?',
    ];
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text('My First App'),
        ),
        body: Column(
          children: <Widget>[
            Question(
              questions[_questionIndex],
            ),
            ElevatedButton(
              child: Text(
                'Answer 1',
              ),
              onPressed: _answerQuestion,
            ),
            ElevatedButton(
              child: Text(
                'Answer 2',
              ),
              onPressed: _answerQuestion,
            ),
            ElevatedButton(
              child: Text(
                'Answer 3',
              ),
              onPressed: _answerQuestion,
            )
          ],
        ),
      ),
    );
  }
}
