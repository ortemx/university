from sklearn.datasets import load_wine
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA
import matplotlib.pyplot as plt


# Загрузка данных
data = load_wine()
X = data.data
y = data.target

# Стандартизация данных
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# Применение PCA с двумя компонентами
pca = PCA(n_components=2)
X_pca = pca.fit_transform(X_scaled)

# Визуализация данных
plt.scatter(X_pca[:, 0], X_pca[:, 1], c=y)
plt.xlabel('PC1')
plt.ylabel('PC2')
plt.savefig("D:/GH/university/term6/Kursach/pngmy_plot.png")
print((data['data'][0]))