//guide: Dr. James Smith.
//Code Reference: EECS 2021 LAB designed by Dr. James Smith.
package sample;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.io.IOException;

public class Main extends Application {
    private final static int MAX_MoistureSensor_VALUE = 1 << 10;
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        var sp = SerialPortService.getSerialPort("/dev/cu.usbserial-0001");
        var outputStream = sp.getOutputStream();
        var pane = new BorderPane();

        var controller = new DataController(); // create the controller

        var button = new Button("PUMP ON/OFF");

        button.setOnMousePressed(value ->{
            try{
                outputStream.write(50);
            }catch(IOException e){
                e.printStackTrace();
            }
        });
        button.setOnMouseReleased(value ->{
            try{
                outputStream.write(0);
            }catch(IOException e){
                e.printStackTrace();
            }
        });
        button.setPrefWidth(200); //button width
        button.setPrefHeight(30); //Button Height
        button.setTranslateX(0); //Set Button position on x-axis
        button.setTranslateY(100); //Set Button position on y-axis

        var button2 = new Button("FAN ON/OFF");

        button2.setOnMousePressed(value ->{
            try{
                outputStream.write(100);
            }catch(IOException e){
                e.printStackTrace();
            }
        });
        button2.setOnMouseReleased(value ->{
            try{
                outputStream.write(0);
            }catch(IOException e){
                e.printStackTrace();
            }
        });
        button2.setPrefWidth(200); //button width
        button2.setPrefHeight(30); //Button Height

        var button3 = new Button("HEATER ON/OFF");

        button3.setOnMousePressed(value ->{
            try{
                outputStream.write(150);
            }catch(IOException e){
                e.printStackTrace();
            }
        });
        button3.setOnMouseReleased(value ->{
            try{
                outputStream.write(0);
            }catch(IOException e){
                e.printStackTrace();
            }
        });
        button3.setPrefWidth(200); //button width
        button3.setPrefHeight(30); //Button Height

        var button4= new Button("LIGHT ON/OFF");

        button4.setOnMousePressed(value ->{
            try{
                outputStream.write(200);
            }catch(IOException e){
                e.printStackTrace();
            }
        });
        button4.setOnMouseReleased(value ->{
            try{
                outputStream.write(0);
            }catch(IOException e){
                e.printStackTrace();
            }
        });
        button4.setPrefWidth(200); //button width
        button4.setPrefHeight(30); //Button Height
        button4.setTranslateX(380); //Set Button position on x-axis  //reference of code http://tutorials.jenkov.com/javafx/button.html
        button4.setTranslateY(0); //Set Button position on y-axis

        sp.addDataListener(controller);
        primaryStage.setTitle("MAJOR PROJECT");
        var now = System.currentTimeMillis();
        var xAxis = new NumberAxis("TIME", now, now + 50000, 10000); // creates the x-axis (which automatically updates)
        var yAxis = new NumberAxis("SOIL MOISTURE LEVEL", 0, MAX_MoistureSensor_VALUE, 10); // creates the y-axis
        var series = new XYChart.Series<>(controller.getDataPoints()); // creates the series (all the data)
        var lineChart = new LineChart<>(xAxis, yAxis, FXCollections.singletonObservableList(series)); // creates the chart
        lineChart.setTitle("MOISTURE SENSOR");

        // TODO: Add a 'listener' to the {@code valueProperty} of the slider. The listener
        //  should write the {@code byteValue()} of the new slider value to the output stream.

        pane.setTop(button);
        pane.setLeft(button2);
        pane.setRight(button3);
        pane.setCenter(button4);
        pane.setBottom(lineChart);
        pane.setPadding(new Insets(0, 20, 0, 20));
        var scene = new Scene(pane, 1000, 600); //1000 width and 600 hight
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}