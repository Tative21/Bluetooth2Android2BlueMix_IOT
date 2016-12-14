package com.example.willi.bluetooth2android;

import android.content.Context;
import android.content.res.Resources;
import weka.classifiers.Classifier;
import weka.classifiers.Evaluation;
import weka.classifiers.trees.J48;
import weka.core.Instances;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;


public class WekaUtils {
    private Context applicationContext;

    public WekaUtils(Context applicationContext) {
        this.applicationContext = applicationContext;
    }

    public void runProgram() throws Exception {

    }
}
