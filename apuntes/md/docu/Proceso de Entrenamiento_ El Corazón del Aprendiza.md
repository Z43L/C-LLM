<img src="https://r2cdn.perplexity.ai/pplx-full-logo-primary-dark%402x.png" class="logo" width="120"/>

# Proceso de Entrenamiento: El Corazón del Aprendizaje Automático

El **proceso de entrenamiento** representa el núcleo fundamental donde las redes neuronales transforman datos en conocimiento, convirtiéndose de simples estructuras matemáticas en sistemas inteligentes capaces de reconocer patrones complejos y realizar predicciones precisas. Este proceso no es simplemente una secuencia de cálculos, sino una danza sofisticada entre matemáticas, optimización y aprendizaje adaptativo que permite a las máquinas emular y, en muchos casos, superar las capacidades cognitivas humanas.

## Función de Pérdida (Loss Function): La Brújula del Aprendizaje

### ¿Qué es una Función de Pérdida?

La **función de pérdida** constituye el corazón matemático del proceso de aprendizaje automático. Esta función actúa como una **brújula cuantitativa** que guía a la red neuronal hacia la dirección correcta, midiendo con precisión matemática la distancia entre las predicciones del modelo y la realidad observada[^1].

**Definición fundamental**: La función de pérdida es una función matemática que mapea los errores de predicción de un modelo a números reales no negativos, donde valores más pequeños indican mejor rendimiento[^2]. Esta función no solo cuantifica el error, sino que proporciona la información direccional necesaria para mejorar el modelo.

### Entropía Cruzada (Cross-Entropy Loss): El Estándar de Oro para Clasificación

La **entropía cruzada** se ha establecido como la función de pérdida predominante para tareas de clasificación, especialmente en el contexto de las redes neuronales modernas. Su elegancia matemática y eficacia práctica la convierten en una herramienta indispensable para el entrenamiento de modelos de inteligencia artificial[^3][^4].

#### Fundamentos Matemáticos de la Entropía Cruzada

**Definición matemática**: Para un problema de clasificación con múltiples clases, la entropía cruzada categórica se define como:

$H(p, q) = -\sum_{i=1}^{C} p_i \log(q_i)$

Donde:

- $p_i$ representa la distribución real (one-hot encoding)
- $q_i$ representa la distribución predicha por el modelo
- $C$ es el número de clases

**Para clasificación binaria**, la fórmula se simplifica a:

$\text{BCE} = -\frac{1}{N}\sum_{i=1}^{N}[y_i \log(\hat{y}_i) + (1-y_i)\log(1-\hat{y}_i)]$

#### ¿Por Qué la Entropía Cruzada es Superior?

La **entropía cruzada** no es solo otra función matemática; es una herramienta especialmente diseñada que ofrece ventajas cruciales sobre alternativas como el error cuadrático medio[^5]:

**1. Gradientes Óptimos**: Cuando el modelo comete errores grandes, la entropía cruzada produce gradientes proporcionalmente grandes, acelerando la corrección del error[^5].

**2. Interpretación Probabilística**: Los valores de salida se interpretan naturalmente como probabilidades, facilitando la toma de decisiones[^3].

**3. Convergencia Rápida**: La función está matemáticamente optimizada para trabajar con la función softmax, creando un paisaje de optimización suave[^6].

#### Ejemplo Práctico: Predicción del Siguiente Token

En modelos de lenguaje como GPT, la entropía cruzada mide qué tan bien el modelo predice la próxima palabra en una secuencia:

**Proceso paso a paso**:

1. **Entrada**: "El cielo es"
2. **Logits del modelo**: [azul: 3.2, verde: 1.1, rojo: 0.8, blanco: 2.9]
3. **Después de Softmax**: [azul: 0.52, verde: 0.06, rojo: 0.05, blanco: 0.37]
4. **Palabra real**: "azul"
5. **Entropía cruzada**: $-\log(0.52) = 0.65$

Un valor más bajo indica una mejor predicción[^3].

### Comparación con Otras Funciones de Pérdida

#### Error Cuadrático Medio (MSE) vs. Entropía Cruzada

**MSE** es ideal para **regresión**, midiendo la diferencia cuadrática entre valores predichos y reales:
$\text{MSE} = \frac{1}{n}\sum_{i=1}^{n}(y_i - \hat{y}_i)^2$

**Entropía Cruzada** es superior para **clasificación** porque[^3][^7]:

- Penaliza más severamente las predicciones incorrectas
- Produce gradientes más informativos
- Se integra naturalmente con funciones de activación como softmax


## Backpropagation (Retropropagación): El Algoritmo del Aprendizaje

### ¿Qué es Backpropagation?

**Backpropagation**, o **retropropagación**, es el algoritmo fundamental que permite a las redes neuronales aprender de sus errores de manera sistemática y eficiente[^8][^9]. Este algoritmo no es simplemente una técnica computacional, sino el mecanismo que hace posible el aprendizaje automático moderno.

**Definición esencial**: Backpropagation es un algoritmo que calcula los gradientes de la función de pérdida con respecto a cada parámetro de la red neuronal, utilizando la regla de la cadena del cálculo diferencial para propagar el error desde la salida hacia las capas de entrada[^10].

### Las Dos Fases del Entrenamiento

#### Fase 1: Propagación Hacia Adelante (Forward Pass)

Durante la **propagación hacia adelante**, los datos fluyen desde la entrada hasta la salida:

1. **Entrada de datos**: Los datos se introducen en la capa de entrada
2. **Transformación por capas**: Cada capa aplica transformaciones lineales y no lineales
3. **Cálculo de la salida**: Se obtiene la predicción final del modelo
4. **Evaluación del error**: Se compara la predicción con el valor real usando la función de pérdida[^11]

#### Fase 2: Propagación Hacia Atrás (Backward Pass)

La **retropropagación** es donde ocurre el aprendizaje real:

1. **Cálculo del gradiente de salida**: Se determina cómo cambió la pérdida respecto a la salida
2. **Aplicación de la regla de la cadena**: Los gradientes se propagan hacia atrás, capa por capa
3. **Cálculo de gradientes parciales**: Para cada peso, se calcula su contribución al error total
4. **Actualización de parámetros**: Los pesos se ajustan en dirección opuesta al gradiente[^9][^12]

### La Regla de la Cadena: El Corazón Matemático

La **regla de la cadena** permite descomponer el cálculo de gradientes complejos en operaciones más simples[^10][^13]:

$\frac{\partial L}{\partial w_{ij}^{(l)}} = \frac{\partial L}{\partial a_j^{(l)}} \cdot \frac{\partial a_j^{(l)}}{\partial z_j^{(l)}} \cdot \frac{\partial z_j^{(l)}}{\partial w_{ij}^{(l)}}$

Donde:

- $L$ es la función de pérdida
- $w_{ij}^{(l)}$ es el peso de la conexión entre la neurona $i$ y $j$ en la capa $l$
- $a_j^{(l)}$ es la activación de la neurona $j$ en la capa $l$
- $z_j^{(l)}$ es la entrada ponderada antes de la función de activación


### Ejemplo Práctico: Cálculo de Gradientes

**Consideremos una red simple con una capa oculta**:

1. **Forward pass**: $z = Wx + b$, $a = \sigma(z)$, $\hat{y} = Wa + b_o$
2. **Pérdida**: $L = \frac{1}{2}(\hat{y} - y)^2$
3. **Gradiente de salida**: $\frac{\partial L}{\partial \hat{y}} = \hat{y} - y$
4. **Gradiente de pesos de salida**: $\frac{\partial L}{\partial W_o} = (\hat{y} - y) \cdot a$
5. **Propagación hacia la capa oculta**: $\frac{\partial L}{\partial a} = (\hat{y} - y) \cdot W_o$

## Optimizadores: Los Algoritmos de Actualización

### Descenso del Gradiente: El Fundamento

El **descenso del gradiente** es el algoritmo de optimización fundamental que utiliza los gradientes calculados por backpropagation para actualizar los parámetros del modelo[^14][^15].

**Fórmula básica**:
$\theta_{t+1} = \theta_t - \alpha \nabla L(\theta_t)$

Donde:

- $\theta$ representa los parámetros del modelo
- $\alpha$ es la tasa de aprendizaje
- $\nabla L(\theta_t)$ es el gradiente de la función de pérdida


### Descenso del Gradiente Estocástico (SGD)

**SGD** introduce una modificación crucial: en lugar de usar todo el conjunto de datos para calcular el gradiente, utiliza **muestras individuales** o **mini-lotes**[^16][^17].

#### Ventajas del SGD

**1. Eficiencia computacional**: Procesa datos de manera incremental, reduciendo los requisitos de memoria[^18].

**2. Escapar de mínimos locales**: Las actualizaciones "ruidosas" pueden ayudar a evitar quedar atrapado en mínimos locales[^19].

**3. Escalabilidad**: Funciona eficientemente con conjuntos de datos masivos[^20].

#### Variantes del SGD

**SGD por lotes**: Utiliza todo el conjunto de datos

- **Ventajas**: Convergencia estable
- **Desventajas**: Costoso computacionalmente

**SGD estocástico**: Una muestra a la vez

- **Ventajas**: Muy rápido, puede escapar de mínimos locales
- **Desventajas**: Convergencia ruidosa

**SGD por mini-lotes**: Compromiso entre ambos

- **Ventajas**: Balance entre eficiencia y estabilidad
- **Desventajas**: Requiere ajuste del tamaño del lote[^15][^21]


### Adam: La Evolución Moderna

**Adam (Adaptive Moment Estimation)** representa una evolución sofisticada del SGD, combinando las mejores características de momentum y adaptación de tasa de aprendizaje[^22][^23].

#### ¿Cómo Funciona Adam?

Adam mantiene **dos momentos** de los gradientes:

**Primer momento (momentum)**:
$m_t = \beta_1 m_{t-1} + (1-\beta_1)g_t$

**Segundo momento (varianza)**:
$v_t = \beta_2 v_{t-1} + (1-\beta_2)g_t^2$

**Corrección de sesgo**:
$\hat{m}_t = \frac{m_t}{1-\beta_1^t}, \quad \hat{v}_t = \frac{v_t}{1-\beta_2^t}$

**Actualización final**:
$\theta_{t+1} = \theta_t - \frac{\alpha}{\sqrt{\hat{v}_t} + \epsilon}\hat{m}_t$

#### Ventajas de Adam

**1. Tasas de aprendizaje adaptivas**: Cada parámetro tiene su propia tasa de aprendizaje que se ajusta automáticamente[^24].

**2. Robustez**: Menos sensible a la elección de hiperparámetros que SGD[^25].

**3. Convergencia rápida**: Típicamente converge más rápido que SGD en muchos problemas[^26].

**4. Manejo del ruido**: Combina momentum con adaptación, manejando eficientemente gradientes ruidosos[^23].

### SGD vs. Adam: ¿Cuándo Usar Cada Uno?

#### Cuándo Usar SGD

**1. Control preciso**: Cuando necesitas control fino sobre el proceso de optimización[^26].

**2. Generalización**: SGD a menudo produce modelos que generalizan mejor[^27].

**3. Problemas simples**: Para modelos más simples donde la eficiencia de Adam no es crucial[^19].

**4. Investigación**: Cuando quieres entender completamente el comportamiento del optimizador[^28].

#### Cuándo Usar Adam

**1. Prototipado rápido**: Cuando necesitas resultados rápidos con mínimo ajuste[^25].

**2. Grandes conjuntos de datos**: Adam maneja eficientemente datos masivos[^24].

**3. Redes complejas**: Para arquitecturas profundas y complejas[^23].

**4. Datos no estacionarios**: Cuando las distribuciones de datos cambian con el tiempo[^26].

## El Proceso Completo: Uniendo Todas las Piezas

### Ciclo de Entrenamiento Paso a Paso

**1. Inicialización**:

- Los pesos se inicializan aleatoriamente
- Se establecen hiperparámetros (tasa de aprendizaje, tamaño de lote)
- Se preparan los datos de entrenamiento[^29][^30]

**2. Forward Pass**:

- Los datos pasan por la red capa por capa
- Se calculan las activaciones y la salida final
- Se evalúa la función de pérdida[^31][^32]

**3. Backward Pass**:

- Se calcula el gradiente de la pérdida respecto a la salida
- Los gradientes se propagan hacia atrás usando la regla de la cadena
- Se calculan los gradientes para todos los parámetros[^8][^33]

**4. Actualización de Parámetros**:

- El optimizador ajusta los pesos usando los gradientes
- Se prepara para la siguiente iteración[^11][^34]

**5. Evaluación**:

- Se monitorea el progreso del entrenamiento
- Se verifica la convergencia y el rendimiento[^35][^36]


### Monitoreo del Entrenamiento

**Métricas clave a observar**:

**Pérdida de entrenamiento**: Debe decrecer consistentemente[^37].

**Pérdida de validación**: Indica la capacidad de generalización[^38].

**Precisión**: Mide el rendimiento en tareas de clasificación[^30].

**Gradientes**: Deben mantener magnitudes apropiadas (ni muy grandes ni muy pequeños)[^32].

## Ejemplo Práctico: Entrenamiento de una Red Neuronal

### Código de Implementación

```python
import tensorflow as tf
import numpy as np

# Preparación de datos
X_train = np.random.randn(1000, 784)  # Imágenes 28x28 aplanadas
y_train = tf.keras.utils.to_categorical(np.random.randint(0, 10, 1000))

# Definición del modelo
model = tf.keras.Sequential([
    tf.keras.layers.Dense(128, activation='relu', input_shape=(784,)),
    tf.keras.layers.Dense(64, activation='relu'),
    tf.keras.layers.Dense(10, activation='softmax')
])

# Compilación con entropía cruzada y Adam
model.compile(
    optimizer=tf.keras.optimizers.Adam(learning_rate=0.001),
    loss='categorical_crossentropy',
    metrics=['accuracy']
)

# Entrenamiento
history = model.fit(
    X_train, y_train,
    epochs=50,
    batch_size=32,
    validation_split=0.2,
    verbose=1
)
```


### Interpretación de Resultados

**Progreso típico del entrenamiento**:

- **Época 1**: Pérdida alta (~2.3), precisión baja (~10%)
- **Época 10**: Pérdida media (~1.5), precisión mejorando (~40%)
- **Época 50**: Pérdida baja (~0.3), precisión alta (~90%)[^37]


## Desafíos y Consideraciones Avanzadas

### Problemas Comunes en el Entrenamiento

**1. Gradientes que se desvanecen**: Los gradientes se vuelven extremadamente pequeños en capas profundas[^32].

**2. Gradientes que explotan**: Los gradientes crecen exponencialmente, causando inestabilidad[^37].

**3. Sobreajuste**: El modelo memoriza los datos de entrenamiento pero no generaliza[^38].

**4. Convergencia lenta**: El entrenamiento progresa muy lentamente[^36].

### Soluciones Modernas

**1. Normalización por lotes**: Estabiliza el entrenamiento y acelera la convergencia[^32].

**2. Dropout**: Previene el sobreajuste desactivando aleatoriamente neuronas[^30].

**3. Conexiones residuales**: Facilitan el flujo de gradientes en redes profundas[^32].

**4. Ajuste adaptativo de la tasa de aprendizaje**: Optimizadores como Adam se adaptan automáticamente[^26].

## Aplicaciones del Mundo Real

### Procesamiento de Lenguaje Natural

En modelos como GPT-4, el proceso de entrenamiento involucra:

- **Datos**: Billones de tokens de texto
- **Función de pérdida**: Entropía cruzada para predicción del siguiente token
- **Optimizador**: Adam con ajustes especializados
- **Escala**: Miles de millones de parámetros[^23]


### Visión Computacional

Para tareas como reconocimiento de imágenes:

- **Datos**: Millones de imágenes etiquetadas
- **Arquitectura**: Redes convolucionales profundas
- **Función de pérdida**: Entropía cruzada categórica
- **Optimización**: SGD con momentum o Adam[^27]


### Aplicaciones Médicas

En diagnóstico por imagen médica:

- **Precisión crítica**: Errores pueden tener consecuencias graves
- **Datos especializados**: Imágenes médicas de alta resolución
- **Validación rigurosa**: Múltiples conjuntos de prueba independientes[^39]


## El Futuro del Entrenamiento de Redes Neuronales

### Tendencias Emergentes

**1. Entrenamiento distribuido**: Paralelización masiva en múltiples GPUs y servidores[^23].

**2. Optimizadores adaptativos avanzados**: Nuevas variantes de Adam con mejor generalización[^26].

**3. Aprendizaje auto-supervisado**: Reducción de la dependencia de datos etiquetados[^24].

**4. Eficiencia energética**: Técnicas para reducir el consumo computacional[^36].

### Desafíos Futuros

**1. Escalabilidad**: Entrenar modelos con trillones de parámetros[^23].

**2. Interpretabilidad**: Entender por qué y cómo aprenden los modelos[^38].

**3. Robustez**: Crear modelos resistentes a ataques adversarios[^32].

**4. Democratización**: Hacer el entrenamiento accesible a más desarrolladores[^36].

## Conclusión: El Arte y la Ciencia del Entrenamiento

El **proceso de entrenamiento** de redes neuronales representa una convergencia fascinante entre matemáticas puras, ingeniería computacional y intuición práctica. Cada componente, desde la elegante simplicidad de la **entropía cruzada** hasta la sofisticada adaptabilidad de **Adam**, desempeña un papel crucial en la transformación de estructuras matemáticas estáticas en sistemas inteligentes dinámicos.

La **función de pérdida** actúa como el compass moral del aprendizaje automático, proporcionando no solo una medida de rendimiento sino una guía direccional para la mejora. La **entropía cruzada**, en particular, se ha establecido como el estándar de oro para clasificación debido a su capacidad única de generar gradientes informativos y convergencia rápida[^3][^5].

**Backpropagation** no es simplemente un algoritmo; es el mecanismo fundamental que hace posible el aprendizaje profundo moderno. Su capacidad para calcular gradientes precisos en redes de cualquier profundidad, utilizando la elegante matemática de la regla de la cadena, ha democratizado el entrenamiento de modelos complejos[^8][^10].

Los **optimizadores** como SGD y Adam representan diferentes filosofías de aprendizaje: SGD enfatiza el control y la simplicidad, mientras que Adam prioriza la adaptabilidad y la eficiencia. La elección entre ellos no es meramente técnica, sino que refleja las prioridades específicas del problema y los recursos disponibles[^19][^26].

En un mundo donde la inteligencia artificial está transformando industrias enteras, desde la medicina hasta el entretenimiento, desde las finanzas hasta la investigación científica, comprender estos procesos fundamentales de entrenamiento se vuelve crucial no solo para científicos de datos e ingenieros de IA, sino para cualquier profesional que busque aprovechar el poder transformador de estas tecnologías.

El futuro del entrenamiento de redes neuronales promete ser aún más emocionante, con desarrollos en optimización distribuida, aprendizaje auto-supervisado y eficiencia computacional que continuarán empujando los límites de lo que es posible. Sin embargo, los principios fundamentales que hemos explorado, la danza entre pérdida, gradientes y optimización, continuarán siendo la base sobre la cual se construirá la próxima generación de sistemas inteligentes.

El entrenamiento de redes neuronales es, en última instancia, un proceso de traducir la experiencia humana y el conocimiento del dominio en representaciones matemáticas que las máquinas pueden entender y utilizar. Es la alquimia moderna que transforma datos en inteligencia, números en comprensión, y cálculos en capacidades que, hace apenas unas décadas, considerábamos exclusivamente humanas.

<div style="text-align: center">⁂</div>

[^1]: https://www.ibm.com/think/topics/loss-function

[^2]: https://www.datacamp.com/tutorial/loss-function-in-machine-learning

[^3]: https://www.innovatiana.com/es/post/cross-entropy-loss

[^4]: https://inteligenciaartificial360.com/glosario/entropia-cruzada/

[^5]: https://www.youtube.com/watch?v=NweFOol6e_s

[^6]: https://www.manuduque.com/enciclopedia-ia/cross-entropy/

[^7]: https://www.linkedin.com/advice/3/how-does-cross-entropy-mean-squared-error-affect?lang=es

[^8]: https://antonio-richaud.com/blog/archivo/publicaciones/40-backpropagation.html

[^9]: https://gamco.es/glosario/retropropagacion/

[^10]: https://www.ibm.com/es-es/think/topics/backpropagation

[^11]: https://msmk.university/backpropagation/

[^12]: https://www.unir.net/revista/ingenieria/backpropagation/

[^13]: https://es.wikipedia.org/wiki/Retropropagación

[^14]: https://www.ibm.com/es-es/think/topics/gradient-descent

[^15]: https://es.innovatiana.com/post/gradient-descent

[^16]: https://es.wikipedia.org/wiki/Descenso_de_gradiente_estoc%C3%A1stico

[^17]: https://gamco.es/glosario/descenso-de-gradiente-estocastico-sgd/

[^18]: https://www.ultralytics.com/es/glossary/stochastic-gradient-descent-sgd

[^19]: https://codelabsacademy.com/es/blog/gradient-descent-and-stochastic-gradient-descent-in-machine-leaning

[^20]: https://qu4nt.github.io/sklearn-doc-es/modules/sgd.html

[^21]: https://keepcoding.io/blog/metodo-por-descenso-de-gradientes/

[^22]: https://interactivechaos.com/es/manual/tutorial-de-machine-learning/adam

[^23]: https://www.ultralytics.com/es/glossary/adam-optimizer

[^24]: https://konfuzio.com/es/estimacion-adaptativa-de-momentos/

[^25]: https://www.datacamp.com/es/tutorial/adam-optimizer-tutorial

[^26]: https://certidevs.com/tutorial-tensorflow-optimizadores-adam-sgd-rmsprop

[^27]: https://pistaseducativas.celaya.tecnm.mx/index.php/pistas/article/view/2300

[^28]: https://www.datacamp.com/es/tutorial/stochastic-gradient-descent

[^29]: https://es.linkedin.com/pulse/deep-learning-los-4-pasos-para-construir-un-modelo-mitaritonna

[^30]: https://data-universe.org/desarrollo-de-redes-neuronales-en-deep-learning-pasos-clave/

[^31]: https://carlosjuliopardoblog.wordpress.com/2018/02/06/machine-learning-backpropagation-reconocimiento-de-digitos-escritos-a-mano/

[^32]: https://certidevs.com/tutorial-tensorflow-backpropagation-algoritmos-redes-neuronales

[^33]: https://msmk.university/red-neuronal-de-retropropagacion-backpropagation-neural-network/

[^34]: https://www.universidadviu.com/es/actualidad/nuestros-expertos/como-funciona-un-algoritmo-de-backpropagation

[^35]: https://www.aprendemachinelearning.com/7-pasos-machine-learning-construir-maquina/

[^36]: https://www.tokioschool.com/noticias/como-entrenar-modelo-machine-learning/

[^37]: https://www.youtube.com/watch?v=Tb8f_KCjCjI

[^38]: https://mindfulml.vialabsdigital.com/post/como-aprende-una-red-neuronal/

[^39]: https://saishnp.com/2024/01/18/3-ejemplos-de-entrenamientos-de-redes-neuronales-mediante-deep-learning-para-el-analisis-de-imagenes-mediante-la-inteligencia-artificial-ia/

[^40]: https://ignaciogavilan.com/catalogo-de-componentes-de-redes-neuronales-iii-funciones-de-perdida/

[^41]: https://magistereninteligenciaartificial.cl/descubre-como-la-entropia-cruzada-revoluciona-el-mundo-digital/

[^42]: https://builtin.com/machine-learning/common-loss-functions

[^43]: https://dialektico.com/funcion-perdida-regresion-logistica/

[^44]: https://www.datacamp.com/es/tutorial/the-cross-entropy-loss-function-in-machine-learning

[^45]: https://codificandobits.com/curso/fundamentos-deep-learning-python/redes-neuronales-9-entropia-cruzada-entrenamiento-neurona-artificial/

[^46]: https://www.geeksforgeeks.org/ml-common-loss-functions/

[^47]: https://en.wikipedia.org/wiki/Loss_function

[^48]: https://www.youtube.com/watch?v=mSqaQt6Dnow

[^49]: https://lamaquinaoraculo.com/deep-learning/aprendizaje-de-redes-neuronales/

[^50]: https://www.youtube.com/watch?v=v_ueBW_5dLg

[^51]: https://www.linkedin.com/advice/0/what-advantages-disadvantages-using-cross-entropy?lang=es

[^52]: https://www.youtube.com/watch?v=INLw53uLuY8

[^53]: https://www.cs.us.es/~fsancho/ficheros/IAML/2016/Sesion04/capitulo_BP.pdf

[^54]: https://www.freecodecamp.org/espanol/news/descenso-de-gradiente-ejemplo-de-algoritmo-de-aprendizaje-automaticod/

[^55]: https://www.youtube.com/watch?v=ScVpPS_CFYc

[^56]: https://formacion.intef.es/aulaenabierto/mod/book/view.php?id=5077\&chapterid=6493\&lang=en

[^57]: https://es.wikipedia.org/wiki/Descenso_del_gradiente

[^58]: https://www.ultralytics.com/es/glossary/gradient-descent

[^59]: https://universidadeuropea.com/blog/backpropagation/

[^60]: https://www.vernegroup.com/actualidad/tecnologia/descenso-gradiente-brujula-machine-learning/

[^61]: https://www.youtube.com/watch?v=tLY-gNoGEPs

[^62]: https://www.ultralytics.com/glossary/adam-optimizer

[^63]: https://www.youtube.com/watch?v=iyMFcF36gO0

[^64]: https://www.geeksforgeeks.org/deep-learning/adam-optimizer/

[^65]: https://www.reddit.com/r/MachineLearning/comments/qq75zu/d_how_do_you_choose_an_optimizer_and_why_are/?tl=es-es

[^66]: https://www.riego.mx/congresos/comeii2021/files/ponencias/extenso/COMEII-21005.pdf

[^67]: https://pistaseducativas.celaya.tecnm.mx/index.php/pistas/article/viewFile/2300/1846

[^68]: https://www.datacamp.com/tutorial/adam-optimizer-tutorial

[^69]: https://webs.um.es/juanbot/miwiki/lib/exe/fetch.php%3Fid=tiia\&cache=cache\&media=clase_tiia7.pdf

[^70]: https://www.youtube.com/watch?v=_-PGy0hIjys

[^71]: https://www.youtube.com/watch?v=_sej5wurIsg

[^72]: https://la.mathworks.com/campaigns/offers/deep-learning-examples-with-matlab.html

[^73]: https://www.futurespace.es/en/redes-neuronales-y-deep-learning-brackpropagation/

[^74]: https://developers.google.com/machine-learning/crash-course/neural-networks/interactive-exercises

[^75]: https://www.youtube.com/watch?v=iOsR-EC9z6I

[^76]: https://www.youtube.com/watch?v=A1zfrUHpILs

[^77]: https://www.youtube.com/watch?v=iX_on3VxZzk

[^78]: https://interactivechaos.com/es/manual/tutorial-de-machine-learning/backpropagation

