<img src="https://r2cdn.perplexity.ai/pplx-full-logo-primary-dark%402x.png" class="logo" width="120"/>

# Arquitectura Básica de una Red Neuronal: El Corazón de la Inteligencia Artificial Moderna

Las **redes neuronales artificiales** representan uno de los avances más revolucionarios en el campo de la inteligencia artificial, constituyendo la base arquitectónica sobre la cual se construyen todos los sistemas de aprendizaje profundo modernos. Estas estructuras computacionales no son simplemente herramientas matemáticas abstractas, sino sistemas sofisticados que emulan el funcionamiento del cerebro humano para resolver problemas complejos de manera automatizada.

## Neuronas (Nodos) y Pesos (Weights): Los Bloques Fundamentales del Aprendizaje

### ¿Qué es una Neurona Artificial?

Una **neurona artificial**, también conocida como nodo o unidad de procesamiento, es el elemento básico de computación en una red neuronal. Esta unidad emula el comportamiento de una neurona biológica real, pero implementada mediante operaciones matemáticas precisas[^1]. Cada neurona artificial recibe múltiples señales de entrada, las procesa y genera una señal de salida que puede servir como entrada para otras neuronas[^2].

**Funcionamiento detallado de una neurona**:

1. **Recepción de entradas**: La neurona recibe valores numéricos desde múltiples fuentes
2. **Procesamiento**: Calcula una suma ponderada de todas las entradas
3. **Transformación**: Aplica una función de activación al resultado
4. **Transmisión**: Envía el resultado a las neuronas de la siguiente capa

### Los Pesos (Weights): La Memoria del Aprendizaje

Los **pesos sinápticos** son parámetros numéricos fundamentales que determinan la importancia relativa de cada conexión entre neuronas[^3]. Cada conexión entre dos neuronas tiene asociado un peso específico que modifica la intensidad de la señal que se transmite[^4].

**Características esenciales de los pesos**:

- **Valores ajustables**: Pueden ser positivos, negativos o cero
- **Memoria del modelo**: Almacenan el conocimiento aprendido durante el entrenamiento
- **Determinantes del comportamiento**: Definen cómo responde la red a diferentes entradas
- **Optimización continua**: Se ajustan mediante algoritmos de aprendizaje


### El Sesgo (Bias): El Umbral de Activación

El **bias** o sesgo es un parámetro adicional que se suma a la suma ponderada de las entradas[^1]. Este componente permite a la neurona ajustar su punto de activación, proporcionando mayor flexibilidad al modelo para aprender patrones complejos[^5].

**Fórmula matemática fundamental**:
$y = f\left(\sum_{i=1}^{n} w_i \cdot x_i + b\right)$

Donde:

- $x_i$ son las entradas
- $w_i$ son los pesos correspondientes
- $b$ es el sesgo
- $f$ es la función de activación
- $y$ es la salida de la neurona


## Capas (Layers): La Organización Jerárquica del Procesamiento

### Arquitectura en Capas: Una Estructura Organizada

Las redes neuronales organizan sus neuronas en **capas estructuradas** que procesan la información de manera secuencial y jerárquica. Esta organización permite que cada capa se especialice en detectar y procesar diferentes niveles de abstracción en los datos[^2].

**Tipos fundamentales de capas**:

#### 1. Capa de Entrada (Input Layer)

La **capa de entrada** es el punto de acceso donde los datos externos ingresan a la red neuronal[^6]. Estrictamente hablando, esta capa no realiza computación, sino que simplemente recibe y distribuye los datos a las capas subsiguientes[^2].

**Características de la capa de entrada**:

- **No tiene pesos**: Solo recibe y transmite datos
- **Dimensión fija**: El número de neuronas coincide con las características de entrada
- **Normalización**: A menudo los datos se procesan antes de ingresar


#### 2. Capas Ocultas (Hidden Layers)

Las **capas ocultas** constituyen el núcleo del procesamiento en una red neuronal[^2]. Estas capas reciben este nombre porque no tienen contacto directo con el exterior, operando como transformadores internos de la información[^7].

**Funciones de las capas ocultas**:

- **Extracción de características**: Identifican patrones relevantes en los datos
- **Transformación no lineal**: Introducen complejidad mediante funciones de activación
- **Jerarquía de abstracción**: Cada capa detecta características más complejas
- **Especialización**: Diferentes neuronas se especializan en diferentes patrones


#### 3. Capa de Salida (Output Layer)

La **capa de salida** es responsable de producir el resultado final de la red neuronal[^8]. Su estructura y función dependen del tipo de problema que se está resolviendo.

**Configuraciones típicas**:

- **Clasificación binaria**: Una neurona con función sigmoid
- **Clasificación multiclase**: Múltiples neuronas con función softmax
- **Regresión**: Una o más neuronas con función lineal


### Conectividad y Flujo de Información

En una red neuronal **feedforward** típica, la información fluye unidireccionalmente desde la capa de entrada hasta la capa de salida[^9]. Cada neurona en una capa está conectada a todas las neuronas de la capa siguiente, creando una arquitectura **totalmente conectada**[^10].

## Funciones de Activación: Introduciendo No-Linealidad

### ¿Por Qué Son Esenciales las Funciones de Activación?

Las **funciones de activación** son componentes cruciales que introducen **no-linealidad** en las redes neuronales[^11]. Sin estas funciones, una red neuronal multicapa se comportaría como un simple modelo lineal, limitando drásticamente su capacidad de aprendizaje[^12].

**Importancia fundamental**:

- **No-linealidad**: Permiten modelar relaciones complejas
- **Capacidad de aproximación**: Habilitan la aproximación de funciones arbitrarias
- **Especialización neuronal**: Determinan cuándo y cómo se activa cada neurona
- **Gradiente**: Facilitan el flujo de gradientes durante el entrenamiento


### ReLU (Rectified Linear Unit): La Función Dominante

La función **ReLU** se ha convertido en la función de activación más utilizada en redes neuronales modernas debido a su simplicidad y eficacia[^13][^14].

**Definición matemática**:
$\text{ReLU}(x) = \max(0, x)$

**Ventajas de ReLU**:

- **Eficiencia computacional**: Extremadamente rápida de calcular[^12]
- **Gradientes estables**: No sufre de desvanecimiento del gradiente para valores positivos
- **Esparsidad**: Introduce esparsidad natural en la red
- **Convergencia rápida**: Acelera el entrenamiento

**Limitaciones de ReLU**:

- **Neuronas muertas**: Pueden "morir" durante el entrenamiento[^15]
- **No centrada en cero**: Salida siempre no negativa
- **Gradiente cero**: Para entradas negativas no contribuye al aprendizaje


### GELU (Gaussian Error Linear Unit): La Evolución Moderna

**GELU** representa una evolución sofisticada de ReLU, incorporando propiedades probabilísticas que mejoran el rendimiento en muchas aplicaciones[^15].

**Definición matemática**:
$\text{GELU}(x) = x \cdot \Phi(x)$

Donde $\Phi(x)$ es la función de distribución acumulativa gaussiana estándar.

**Ventajas de GELU**:

- **Suavidad**: Función diferenciable en todos los puntos
- **Probabilística**: Incorpora incertidumbre de manera natural
- **Rendimiento superior**: Mejores resultados en transformers y modelos de lenguaje
- **Regularización implícita**: Proporciona regularización automática


## Softmax: La Función Clave para Distribuciones de Probabilidad

### ¿Qué es Softmax y Por Qué es Fundamental?

La función **Softmax** es una función de activación especializada que convierte un vector de puntuaciones brutas (logits) en una distribución de probabilidad[^16]. Esta función es absolutamente esencial para tareas de clasificación multiclase[^17].

**Definición matemática**:
$\text{Softmax}(z_i) = \frac{e^{z_i}}{\sum_{j=1}^{K} e^{z_j}}$

Donde $z_i$ son las puntuaciones de entrada y $K$ es el número de clases.

### Propiedades Matemáticas Cruciales

**Características fundamentales de Softmax**:

1. **Normalización**: La suma de todas las salidas es exactamente 1
2. **Probabilidades válidas**: Todas las salidas están entre 0 y 1
3. **Interpretabilidad**: Cada salida representa la probabilidad de una clase
4. **Diferenciabilidad**: Permite el cálculo eficiente de gradientes

### De Logits a Probabilidades: El Proceso de Transformación

Los **logits** son las puntuaciones brutas que produce una red neuronal antes de aplicar cualquier normalización[^18]. Estos valores pueden ser cualquier número real, positivo o negativo, y representan la "confianza" del modelo en cada clase posible[^19].

**Proceso de transformación**:

1. **Generación de logits**: La red produce puntuaciones brutas para cada clase
2. **Exponenciación**: Se aplica la función exponencial para hacer valores positivos
3. **Normalización**: Se divide por la suma total para obtener probabilidades
4. **Interpretación**: El resultado es una distribución de probabilidad válida

### Aplicación Práctica: Predicción del Siguiente Token

En modelos de lenguaje como GPT, la función Softmax es crucial para determinar qué token es más probable que siga en una secuencia[^20]. El proceso funciona de la siguiente manera:

**Ejemplo práctico**:

```
Entrada: "El cielo es"
Logits: [azul: 3.2, verde: 1.1, rojo: 0.8, blanco: 2.9]
Softmax: [azul: 0.52, verde: 0.06, rojo: 0.05, blanco: 0.37]
```

En este ejemplo, "azul" tiene la mayor probabilidad (52%) de ser el siguiente token.

## Arquitectura Feedforward: El Flujo de la Información

### Propagación Hacia Adelante (Forward Propagation)

La **propagación hacia adelante** es el proceso mediante el cual los datos fluyen desde la entrada hasta la salida de la red neuronal[^21]. Este proceso es determinístico y sigue una secuencia específica de cálculos matemáticos[^22].

**Pasos del proceso**:

1. **Entrada de datos**: Los datos se introducen en la capa de entrada
2. **Cálculo por capas**: Cada capa procesa secuencialmente la información
3. **Suma ponderada**: Se calcula $\sum w_i x_i + b$ para cada neurona
4. **Función de activación**: Se aplica la función no lineal correspondiente
5. **Transmisión**: El resultado se envía a la siguiente capa

### Operaciones Matriciales: La Eficiencia Computacional

Las redes neuronales implementan sus cálculos mediante **multiplicaciones matriciales** eficientes[^23]. Esta representación matemática permite un procesamiento paralelo y optimizado.

**Representación matricial**:
$\mathbf{a}^{(l)} = f(\mathbf{W}^{(l)} \mathbf{a}^{(l-1)} + \mathbf{b}^{(l)})$

Donde:

- $\mathbf{a}^{(l)}$ es la activación de la capa $l$
- $\mathbf{W}^{(l)}$ es la matriz de pesos de la capa $l$
- $\mathbf{b}^{(l)}$ es el vector de sesgos de la capa $l$
- $f$ es la función de activación


## Ejemplos Prácticos y Aplicaciones Reales

### Reconocimiento de Imágenes: Detectando Patrones Visuales

En aplicaciones de **reconocimiento de imágenes**, las redes neuronales procesan píxeles como datos de entrada y producen clasificaciones como salida[^24]. Por ejemplo, una red que clasifica animales podría funcionar así:

**Proceso paso a paso**:

1. **Entrada**: Imagen de 224×224×3 píxeles (RGB)
2. **Capas ocultas**: Detectan bordes, texturas, formas y objetos complejos
3. **Capa de salida**: 1000 neuronas (una por cada clase de animal)
4. **Softmax**: Convierte logits en probabilidades
5. **Predicción**: "Gato: 85%, Perro: 12%, Otro: 3%"

### Procesamiento de Lenguaje Natural: Comprendiendo el Texto

En **modelos de lenguaje**, cada palabra se convierte en un vector numérico que la red puede procesar[^25]. El proceso incluye:

**Arquitectura típica**:

- **Tokenización**: Conversión de texto en tokens numéricos
- **Embeddings**: Representación vectorial de palabras
- **Capas transformer**: Procesamiento contextual
- **Capa de salida**: Predicción del siguiente token
- **Softmax**: Distribución de probabilidad sobre el vocabulario


### Sistemas de Recomendación: Personalizando Experiencias

Las redes neuronales en **sistemas de recomendación** aprenden patrones de preferencias de usuarios[^26]:

**Ejemplo de Netflix**:

1. **Entrada**: Historial de visualización, ratings, metadatos
2. **Procesamiento**: Capas ocultas aprenden preferencias latentes
3. **Salida**: Puntuaciones para cada película/serie
4. **Recomendación**: Los ítems con mayor puntuación se sugieren al usuario

## La Inicialización y el Entrenamiento: Dando Vida a la Red

### Inicialización de Parámetros: El Punto de Partida

La **inicialización adecuada** de pesos y sesgos es crucial para el éxito del entrenamiento[^27]. Una inicialización incorrecta puede llevar a problemas como el desvanecimiento o explosión del gradiente.

**Métodos comunes de inicialización**:

- **Xavier/Glorot**: Balanceo óptimo para funciones sigmoid y tanh
- **He**: Especialmente diseñado para funciones ReLU
- **Distribución normal**: Con media 0 y desviación estándar específica


### El Proceso de Aprendizaje: Ajustando los Parámetros

Durante el **entrenamiento**, la red ajusta iterativamente sus pesos y sesgos para minimizar el error entre las predicciones y los valores reales[^28]. Este proceso utiliza:

**Componentes del entrenamiento**:

1. **Función de pérdida**: Mide la diferencia entre predicción y realidad
2. **Optimizador**: Algoritmo que ajusta los parámetros
3. **Retropropagación**: Calcula gradientes para actualizar pesos
4. **Tasa de aprendizaje**: Controla la velocidad de los ajustes

## Aplicaciones Transformadoras en la Vida Real

### Medicina: Revolucionando el Diagnóstico

En el campo médico, las redes neuronales están **transformando el diagnóstico**[^26]:

- **Análisis de imágenes médicas**: Detección temprana de cáncer en radiografías
- **Predicción de enfermedades**: Análisis de patrones en datos clínicos
- **Personalización de tratamientos**: Adaptación basada en características del paciente


### Transporte: Hacia la Autonomía Completa

Los **vehículos autónomos** dependen completamente de redes neuronales[^29]:

- **Percepción visual**: Reconocimiento de objetos, peatones y señales
- **Toma de decisiones**: Planificación de rutas y maniobras
- **Predicción de comportamiento**: Anticipación de acciones de otros conductores


### Finanzas: Detectando Patrones Complejos

En el sector financiero, las redes neuronales proporcionan[^29]:

- **Detección de fraude**: Identificación de transacciones sospechosas
- **Trading algorítmico**: Decisiones de inversión automatizadas
- **Evaluación crediticia**: Análisis de riesgo personalizado


## El Futuro de las Arquitecturas Neuronales

### Tendencias Emergentes

Las **arquitecturas modernas** están evolucionando hacia diseños más sofisticados:

- **Redes residuales**: Conexiones que saltan capas para facilitar el entrenamiento
- **Arquitecturas attention**: Mecanismos que permiten focalización selectiva
- **Redes neuromórficas**: Diseños inspirados directamente en el cerebro biológico


### Desafíos y Oportunidades

Los principales desafíos incluyen:

- **Eficiencia energética**: Reducir el consumo computacional
- **Interpretabilidad**: Hacer los modelos más explicables
- **Generalización**: Mejorar el rendimiento en datos no vistos
- **Escalabilidad**: Manejar datasets cada vez más grandes


## Conclusión: La Base de la Revolución Tecnológica

La **arquitectura básica de redes neuronales** representa mucho más que una simple técnica computacional; constituye el fundamento sobre el cual se está construyendo la revolución de la inteligencia artificial moderna. Cada componente, desde las neuronas individuales hasta las funciones de activación sofisticadas como Softmax, desempeña un papel crucial en la capacidad de estos sistemas para aprender, adaptar y resolver problemas complejos.

Las **neuronas artificiales** con sus pesos y sesgos forman la unidad básica de procesamiento que permite el aprendizaje adaptativo. La **organización en capas** proporciona la estructura jerárquica necesaria para procesar información de manera progresivamente más abstracta. Las **funciones de activación** como ReLU y GELU introducen la no-linealidad esencial que permite a las redes modelar relaciones complejas del mundo real.

La función **Softmax**, en particular, representa un logro matemático elegante que convierte puntuaciones brutas en distribuciones de probabilidad interpretables, facilitando la toma de decisiones en tareas de clasificación y la predicción del siguiente token en modelos de lenguaje.

Estas arquitecturas no son simplemente construcciones teóricas, sino herramientas prácticas que están **transformando industrias enteras**: desde el diagnóstico médico hasta los vehículos autónomos, desde los sistemas de recomendación hasta el procesamiento de lenguaje natural. Cada aplicación demuestra el poder de estos principios arquitectónicos fundamentales.

A medida que avanzamos hacia el futuro, la comprensión profunda de estos conceptos básicos se vuelve cada vez más crucial. No solo para científicos de datos e ingenieros de IA, sino para cualquier profesional que busque entender y aprovechar las capacidades transformadoras de la inteligencia artificial moderna. La arquitectura de redes neuronales no es solo la base técnica de la IA actual; es la **piedra angular sobre la cual se construirá el futuro tecnológico de nuestra sociedad**.

<div style="text-align: center">⁂</div>

[^1]: https://futurelab.mx/redes neuronales/inteligencia artificial/2019/06/25/intro-a-redes-neuronales-pt-1/

[^2]: https://interactivechaos.com/es/manual/tutorial-de-machine-learning/estructura-de-una-red-neuronal

[^3]: https://www.cs.us.es/~fsancho/Blog/posts/Redes_Neuronales/

[^4]: https://www.angelvillazon.com/inteligencia-artificial-robotica/redes-neuronales-conceptos-2/

[^5]: https://interactivechaos.com/es/manual/tutorial-de-deep-learning/inicializacion-de-los-parametros

[^6]: https://www.ibm.com/docs/es/spss-modeler/saas?topic=networks-neural-model

[^7]: https://interactivechaos.com/es/manual/tutorial-de-deep-learning/tipos-de-capas

[^8]: https://es.eitca.org/inteligencia-artificial/eitc-ai-dltf-aprendizaje-profundo-con-tensorflow/tensorflow/modelo-de-red-neuronal/examen-revisión-modelo-de-red-neuronal/¿Cuál-es-la-diferencia-entre-la-capa-de-salida-y-las-capas-ocultas-en-un-modelo-de-red-neuronal-en-tensorflow%3F/

[^9]: https://www.ionos.es/digitalguide/paginas-web/desarrollo-web/feedforward-neural-network/

[^10]: https://www.frro.utn.edu.ar/repositorio/catedras/quimica/5_anio/orientadora1/monograias/matich-redesneuronales.pdf

[^11]: https://www.toolify.ai/es/ai-news-es/gua-completa-de-funciones-de-activacin-en-redes-neuronales-1122301

[^12]: https://www.datacamp.com/es/tutorial/introduction-to-activation-functions-in-neural-networks

[^13]: https://es.wikipedia.org/wiki/Rectificador_(redes_neuronales)

[^14]: https://codificandobits.com/blog/funcion-de-activacion/

[^15]: https://www.youtube.com/watch?v=_0wdproot34

[^16]: https://es.eitca.org/inteligencia-artificial/eitc-ai-tff-tensorflow-fundamentos/tensorflowjs/usando-tensorflow-para-clasificar-imágenes-de-ropa/revisión-de-examen-usando-tensorflow-para-clasificar-imágenes-de-ropa/¿Cuál-es-el-propósito-de-usar-la-función-de-activación-softmax-en-la-capa-de-salida-del-modelo-de-red-neuronal%3F/

[^17]: https://www.toolify.ai/es/ai-news-es/activacin-softmax-en-redes-neuronales-explicacin-y-ejemplos-1094413

[^18]: https://docs.lm-kit.com/lm-kit-net/guides/glossary/logits.html

[^19]: https://learnprompting.org/docs/language-model-inversion/logit2prompt

[^20]: https://www.ultralytics.com/es/glossary/softmax

[^21]: https://biblus.us.es/bibing/proyectos/abreproy/11084/fichero/Memoria+por+capítulos+%2FCapítulo+5.pdf+

[^22]: https://biblus.us.es/bibing/proyectos/abreproy/12166/fichero/Volumen+1+-+Memoria+descriptiva+del+proyecto%2F3+-+Perceptron+multicapa.pdf

[^23]: https://www.toolify.ai/es/ai-news-es/matrices-en-redes-neuronales-fundamentos-y-aplicaciones-3090940

[^24]: https://www.innovatiana.com/es/post/image-classification-in-ai

[^25]: https://decidesoluciones.es/reconocimiento-de-texto/

[^26]: https://www.criteo.com/es/blog/machine-learning-en-la-vida-real-5-aplicaciones-actuales/

[^27]: https://keepcoding.io/blog/inicializacion-pesos-bias-deep-learning/

[^28]: https://mindfulml.vialabsdigital.com/post/como-aprende-una-red-neuronal/

[^29]: https://www.channelpartner.es/pymes/7-aplicaciones-practicas-del-machine-learning-en-la-vida-cotidiana-que-pocos-conocen/

[^30]: https://anestesiar.org/2023/redes-neuronales-artificiales/

[^31]: https://gamco.es/glosario/arquitectura-de-red-neuronal/

[^32]: https://openaccess.uoc.edu/bitstream/10609/138187/23/Data mining_M%C3%B3dulo%204_Clasificaci%C3%B3n,%20redes%20neuronales.pdf

[^33]: https://msmk.university/hidden-layer/

[^34]: http://www.sc.ehu.es/ccwbayes/docencia/mmcc/docs/t8neuronales.pdf

[^35]: https://www.cs.us.es/cursos/iaic-2023/Temas/Redes_Neuronales/

[^36]: https://dcain.etsin.upm.es/~carlos/bookAA/05.3_RNN_ModeloMultiCapa.html

[^37]: https://www.tomorrow.bio/es/post/peso-a-peso-como-se-fortalecen-las-redes-neuronales

[^38]: https://developers.google.com/machine-learning/crash-course/neural-networks/nodes-hidden-layers

[^39]: https://es.wikipedia.org/wiki/Red_neuronal_artificial

[^40]: https://www.elsevier.es/es-revista-medicina-clinica-2-articulo-aproximacion-metodologica-al-uso-redes-neuronales-artificiales-13057536

[^41]: https://www.horusml.com/publicaciones/deep-learning-ques-es-y-para-que-sirve-2

[^42]: https://www.datacamp.com/es/tutorial/pytorch-tutorial-building-a-simple-neural-network-from-scratch

[^43]: https://www.ctrl.cinvestav.mx/~yuw/pdf/MaTesMLP.pdf

[^44]: https://www.datacamp.com/es/blog/rectified-linear-unit-relu

[^45]: https://www.cenidet.edu.mx/archivos/electronica/tesis/2017/371MC_jnj.pdf

[^46]: https://www.datacamp.com/es/tutorial/softmax-activation-function-in-python

[^47]: http://www.scielo.org.co/scielo.php?script=sci_arttext\&pid=S0120-62302011000400018

[^48]: https://felipebravom.com/teaching/regresion.pdf

[^49]: https://jacar.es/funcion-softmax-activacion-para-la-clasificacion/

[^50]: https://interactivechaos.com/es/manual/tutorial-de-deep-learning/funcion-lineal-no-lineal

[^51]: https://es.statisticseasily.com/glosario/¿Qué-es-la-función-Softmax-explicada-en-detalle%3F/

[^52]: https://www.scielo.org.mx/scielo.php?pid=S2448-718X2005000400765\&script=sci_arttext

[^53]: https://www.ultralytics.com/es/glossary/activation-function

[^54]: https://es.wikipedia.org/wiki/Función_SoftMax

[^55]: https://www.ina-pidte.ac.cr/pluginfile.php/101461/mod_resource/content/3/arquitecturas_perceptrones_redes_feedforward.html

[^56]: https://www.diegocalvo.es/perceptron-multicapa/

[^57]: https://chatpaper.com/es/chatpaper/paper/107066

[^58]: https://www.imt.mx/archivos/Publicaciones/PublicacionTecnica/pt406.pdf

[^59]: https://es.wikipedia.org/wiki/Retropropagación

[^60]: https://stackoverflow.com/questions/62703391/estimate-token-probability-logits-given-a-sentence-without-computing-the-entire

[^61]: https://es.linkedin.com/advice/1/how-do-you-design-architecture-number?lang=es

[^62]: https://www.datacamp.com/es/tutorial/multilayer-perceptrons-in-machine-learning

[^63]: https://help.openai.com/en/articles/5247780-using-logit-bias-to-alter-token-probability-with-the-openai-api

[^64]: https://www.ibm.com/docs/es/spss-statistics/saas?topic=networks-neural-network-structure

[^65]: https://ocw.uc3m.es/pluginfile.php/2241/mod_page/content/38/Explicacion_tema3.pdf

[^66]: https://www.ioactive.com/understanding-logits-and-their-possible-impacts-on-large-language-model-output-safety/

[^67]: https://research.science.eus/documentos/5eb5e35029995206431d31ed

[^68]: https://www.youtube.com/watch?v=_h-qCc2lbmI

[^69]: https://github.com/ggerganov/llama.cpp/issues/6285

[^70]: https://www.youtube.com/watch?v=kkpUjWR-01Y

[^71]: https://es.eitca.org/artificial-intelligence/eitc-ai-dlpp-deep-learning-with-python-and-pytorch/introduction-eitc-ai-dlpp-deep-learning-with-python-and-pytorch/introduction-to-deep-learning-with-python-and-pytorch/examination-review-introduction-to-deep-learning-with-python-and-pytorch/how-does-the-activation-function-in-a-neural-network-determine-whether-a-neuron-fires-or-not/

[^72]: https://dialnet.unirioja.es/descarga/articulo/4806980.pdf

[^73]: https://es.statisticseasily.com/glosario/¿Qué-es-la-suma-ponderada%3F/

[^74]: https://anderfernandez.com/blog/como-programar-una-red-neuronal-desde-0-en-python/

[^75]: https://certidevs.com/tutorial-tensorflow-keras-funciones-de-activacion

[^76]: https://blog.tenea.com/matrices-redes-neuronales/

[^77]: https://platzi.com/discusiones/1457-machine-learning/48834-en-la-funcion-de-activacion-a-que-se-refiere-con-suma-ponderada/

[^78]: https://es.wikipedia.org/wiki/Perceptrón

[^79]: https://europeanvalley.es/noticias/multiplicacion-de-matrices-la-importancia-de-un-algoritmo/

[^80]: https://es.linkedin.com/pulse/la-importancia-de-las-funciones-activación-en-una-red-calvo-martin

[^81]: https://www.youtube.com/watch?v=0cyqjutbo9E

[^82]: https://www.youtube.com/watch?v=C3JjJvwEhbA

[^83]: https://webs.um.es/juanbot/miwiki/lib/exe/fetch.php%3Fid=tiia\&cache=cache\&media=clase_tiia7.pdf

[^84]: https://la.mathworks.com/campaigns/offers/deep-learning-examples-with-matlab.html

[^85]: https://www.pontia.tech/que-es-el-machine-learning-aplicaciones/

[^86]: https://pdf.wondershare.es/ocr/image-recognition.html

[^87]: https://www.youtube.com/watch?v=iX_on3VxZzk

[^88]: https://www.observatoriorh.com/innovacion-y-tecnologia/siete-aplicaciones-practicas-del-machine-learning-en-la-vida-cotidiana-de-las-que-pocos-son-conscientes.html

[^89]: https://www.ibm.com/es-es/think/topics/image-recognition

[^90]: https://developers.google.com/machine-learning/crash-course/neural-networks/interactive-exercises

[^91]: https://www.ibm.com/es-es/think/topics/machine-learning-use-cases

[^92]: https://es.wikipedia.org/wiki/Reconocimiento_%C3%B3ptico_de_caracteres

[^93]: https://saishnp.com/2024/01/18/3-ejemplos-de-entrenamientos-de-redes-neuronales-mediante-deep-learning-para-el-analisis-de-imagenes-mediante-la-inteligencia-artificial-ia/

[^94]: https://www.algotive.ai/es-mx/blog/5-ejemplos-de-machine-learning-que-usas-en-tu-dia-a-dia-y-no-lo-sabias

[^95]: https://cloud.google.com/vision/docs/ocr

[^96]: https://www.nebrija.es/~cmalagon/inco/ejercicios y practicas/Ejercicios_redes_neuronales.pdf

[^97]: https://www.inesdi.com/blog/machine-learning-como-elemento-de-diferenciacion/

