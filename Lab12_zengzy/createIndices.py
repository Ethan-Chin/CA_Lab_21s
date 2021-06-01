import sys
import re

from pyspark import SparkContext,SparkConf

index={}

def flatMapFunc(document):
    """
    document[0] is the document ID (distinct for each document)
    document[1] is a string of all text in that document

    You will need to modify this code.
    """

    documentID = document[0]
    words = re.findall(r"\w+", document[1])

    dist_words=list(set(words))
    # modify here!
    for i in range(len(dist_words)):
        index_buf=[]
        for j in range(len(words)):
            
            if(dist_words[i]==words[j]):
                index_buf.append(j)
        
        dist_words[i]+=" "+documentID
        index[dist_words[i]]=index_buf
    


    return dist_words

def mapFunc(arg):
    """
    You may need to modify this code.
    """
    return (arg, index[arg])

def reduceFunc(arg1, arg2):
    """
    You may need to modify this code.
    """
    return arg1+arg2

def createIndices(file_name, output="spark-wc-out-createIndices"):
    sc = SparkContext("local[8]", "CreateIndices", conf=SparkConf().set("spark.hadoop.validateOutputSpecs", "false"))
    file = sc.sequenceFile(file_name)

    indices = file.flatMap(flatMapFunc) \
                 .map(mapFunc) \
                 .reduceByKey(reduceFunc)

    indices.coalesce(1).saveAsTextFile(output)

""" Do not worry about this """
if __name__ == "__main__":
    argv = sys.argv
    if len(argv) == 2:
        createIndices(argv[1])
    else:
        createIndices(argv[1], argv[2])
