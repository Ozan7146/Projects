
import numpy as np
import pandas as pd

yorumlar = pd.read_csv('Restaurant_Reviews.csv',error_bad_lines=False)

import re
import nltk

from nltk.stem.porter import PorterStemmer
ps = PorterStemmer()

nltk.download('stopwords')
from nltk.corpus import stopwords

#Preprocessing (Önişleme)
derlem = []
for i in range(1000):
    yorum = re.sub('[^a-zA-Z]',' ',yorumlar['Review'][i])
    yorum = yorum.lower()
    yorum = yorum.split()
    yorum = [ps.stem(kelime) for kelime in yorum if not kelime in set(stopwords.words('english'))]
    yorum = ' '.join(yorum)
    derlem.append(yorum)
    
#Feautre Extraction ( Öznitelik Çıkarımı)
#Bag of Words (BOW)
from sklearn.feature_extraction.text import CountVectorizer
cv = CountVectorizer(max_features = 2000) #En fazla kullanılan 2000 kelimeyi alır.2000 sütunluk liste oluşturduk.
X = cv.fit_transform(derlem).toarray() # bağımsız değişken #2000 sütun oluşturduk.
#3.satırda cat varsa 91.kelime cat ise 3.satır 91.kelimeye 1 değeri verilir diğerlerine de 0 verilir 
y = yorumlar.iloc[:,1].values # bağımlı değişken

#Makine Öğrenmesi
from sklearn.cross_validation import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.20, random_state = 0)

from sklearn.naive_bayes import GaussianNB
gnb = GaussianNB()
gnb.fit(X_train,y_train)

y_pred = gnb.predict(X_test)

from sklearn.metrics import confusion_matrix
cm = confusion_matrix(y_test,y_pred)
print(cm)








































