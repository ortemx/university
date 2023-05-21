import cv2
import numpy as np
import joblib

# Загрузка обученной модели
model = joblib.load('D:/GH/university/term6/Kursach/svm_model.pkl')

# Загрузка изображения с числом
image = cv2.imread('D:/GH/university/term6/Kursach/number.png')

# Преобразование изображения в черно-белый формат
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Изменение размера изображения
resized = cv2.resize(gray, (8, 8), interpolation=cv2.INTER_AREA)

# Преобразование изображения в одномерный массив
flattened = np.ravel(resized)

# Подача массива на вход модели и получение предсказания класса числа
prediction = model.predict([flattened])

# Отображение предсказанного числа на экране
cv2.putText(image, str(prediction[0]), (10, 50), cv2.FONT_HERSHEY_SIMPLEX, 2, (0, 255, 0), 2)
cv2.imshow('Number', image)
cv2.waitKey(0)
cv2.destroyAllWindows()
