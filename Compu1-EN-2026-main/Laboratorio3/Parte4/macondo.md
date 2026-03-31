# The Macondian #

Transcripción del encuentro - TOP SECRET - ULTRASECRETO
Solo para ingenieros que firmaron el juramento de mantener confidencialidad absoluta

## Diálogo

Mr. X: (representante de la agencia que contrata a la empresa ARTES)
Buenos días Hector: ¿Cómo le va?

Dr. Hector Solana: (Gerente de Productos y Proyectos de ARTES)
Buenos días (## redactado ##), todo bien por aqui, aunque me siento como un pez fuera del agua.
Jamas habiamos trabajando con una agencia gubernamental tan importante como la suya.
¿Puede darme una idea de este proyecto llamado "Macondo"?

Mr. X:
Bueno no puedo decir mucho sobre el proyecto por dos razones:
- Macondo está clasificado: yo no puedo compartir lo que sé, y ..
- yo mismo estoy en la obscuridad acerca de gran parte del proyecto!
Pero no se preocupe, van a tener lo que necesitan. Decidimos contratarlos por buenas razones:
ARTES tiene experiencia desarrollando sistemas integrados de procesamiento en tiempo real.

Dr. Solana:
Gracias, nosotros agradecemos que nos hayan elegido para ser parte de este proyecto.
Supongo que ya tienen un plan para ponernos en marcha.

Mr. X:
Asi es. En esta primera fase vamos a programar una simulación parcial del sistema Macondo.
Y digo "vamos" porque nosotros proporcionamos el generador de datos. ARTES se encarga de procesarlos.
El generador simula y envía un flujo de datos de sensores Macondianos, agrupados en "batches" (lotes).
Antes de entrar en más detalles, cuéntenme cómo nos va hasta ahora.

Dr. Solana:
Entiendo, vamos a implementar un procesamiento de flujos de datos, pero ... ¿"sensores Macondianos"?

Mr. X:
Sí, me alegra que lo pregunte. Imaginaba que se quedaría perplejo, y con razón.
Yo mismo no sé qué miden esos sensores, y mucho menos cómo lo hacen: ¡es información clasificada!
Ni siquiera sabemos qué unidades fundamentales están involucradas [1].
Sólo algunos científicos y pocos lideres de la agencia conocen la naturaleza real del proyecto.
La mayoría de nosotros no sabemos quién sabe, quién no, o quién finge no saber.

Dr. Solana:
OMG!

Mr. X:
Como podrá imaginar, se trata de información muy sensible por razones de seguridad nacional.
De hecho, usted me conoce, sabe mi nombre, y ahora sabe que ni siquiera yo sé mucho, y aún así ...
... ¡Me tiene en esta conversación clasificada «TOP SECRET» con el alias "Mr. X"!
Eso es por órdenes de las altas esferas.

Dr. Solana:
Comprendo.

Mr. X:
Y aprecio que ARTES haya sometido a sus ingenieros a un riguroso proceso de evaluación.
Es un proceso largo. Afortunadamente, usted ya está bajo contrato de confidencialidad.
Ya sabe que esta conversación solo puede compartirse con unos pocos de sus ingenieros.

Dr. Solana:
Sí, solo muy pocos de nosotros estamos involucrados en el proyecto, y lo mantenemos en secreto.

Mr. X:
Gracias; puedo imaginar el estrés por el que pasaron algunos, así como la responsabilidad que sienten.
Volviendo a los sensores Macondianos: la buena noticia es que ...
... para ustedes — y, de hecho, también para nosotros — no son nada más que números.
Nuestros científicos crearon un nombre para lo que miden los sensores, y ese nombre es...
... por favor, no se ría ... ¡Macondos!

Dr. Solana:
(Sonriendo) De alguna manera ya me lo imaginaba.
Ud. menciona que recibimos un flujo de datos, de múltiples sensores, "en lotes".
¿Me está diciendo que no vamos a recibir un flujo separado para cada sensor Macondiano?

Mr. X:
Así es: no se obtiene un flujo de datos separado para cada sensor.
Se obtiene un único flujo de lotes: cada uno con las lecturas de todos los sensores.
Para el sistema Macondiano, es fundamental obtener lecturas simultáneas de todos los sensores.
Por eso, nuestros lotes proporcionan datos de todos los sensores del sistema en un momento dado.
Quizás se pregunte cuál es la frecuencia de los lotes y cuántos sensores hay.

Dr. Solana:
Sí, especialmente si tenemos requisitos estrictos en cuanto al tiempo de respuesta.

Mr. X:
Buen punto: ¡por eso contratamos personas que dominan este campo!
La buena noticia es que, primero, vamos a simular el sistema íntegrado en software;
una vez hecho esto, vamos a decidir qué implementar en firmware [2], de ser necesario.

Dr. Solana:
Sí, ese siempre es un buen enfoque.
Me pregunto si el numero de sensores esta prefijado,
y si tienen un estimado de los intervalos de tiempo entre los lotes.

Mr. X:
El número de sensores es un parámetro de la simulación.
Su programa debe depender y funcionar para cualquier valor de los parámetros.
En esta fase, no simulamos intervalos de tiempo entre mensajes por lotes.
Más bien, mediremos (¡y sí, lo haremos!) la sobrecarga del procesamiento de datos y...
...vamos a razonar a la inversa para decidir si procesar los datos mediante software es suficiente.
Tenemos requisitos preliminares de frecuencia mínima de muestreo, basados ​​en la naturaleza del sistema,
pero no necesitamos preocuparnos por eso hasta que conozcamos la sobrecarga del procesamiento de datos.
Mi deseo es que su procesamiento va a ser tan rápido que podremos mantener la frecuencia mínima con holgura.
Por cierto, supongo que no hace falta decirle que deben programar todo en C++.

Dr. Solana:
Claro, la naturaleza de este proyecto lo requiere.
Y conocer la sobrecarga del procesamiento de datos es clave.
Entonces, si entiendo bien, ¿recibiremos lotes de manera continua, sin intervalo de tiempo preestablecido?


Mr. X:
Así es: el generador envía un lote tras otro, en sincronía con el procesamiento..
Tus ingenieros deberían estudiar el generador: no tiene secretos y solo tiene 100 líneas de código.
En ese código podrán notar detalles que no he mencionado hasta ahora.
No los mencioné para que la explicación fuera más fluida y clara.

Dr. Solana:
Comprendo.

Mr. X:
En particular, probablemente imaginas que cada sensor proporciona una única lectura Macondiana...
... pero la realidad es más compleja: cada sensor envía un conjunto de lecturas.
Resulta ser que el sensor Macondiano es un dispositivo compuesto: contiene un arreglo de sensores [3].
A esos los llamamos microsensores. Los Macondos son el promedio de las lecturas de los microsensores.

Dr. Solana:
Entiendo: seguramente es asi para mejorar la fiabilidad de la medida de Macondos.

Mr. X:
Correcto. Y debo agregar que el sensor Macondiano no calcula el promedio: ¡eso lo computan Ustedes!

Dr. Solana:
Ya veo. Eso significa que necesitamos las lecturas de todos los microsensores en cada lote, ¿verdad?

Mr. X:
Asi es.
Debo decirle que los sensores Macondianos vienen en distintos modelos, posiblemente de diferentes proveedores.
Los modelos varian, particularmente en los microsensores, pero cada modelo tiene un número fijo de microsensores.
Los cientificos les dan nombres extraños, inspirados en China y Taiwan, pero dudo que los proveedores sean de alli.
Algunos cuentan que los sensores Chinos tienen más microsensores para compensar la menor calidad de éstos.
Apostaría que estos cuentos son "leyendas de laboratorio" para obfuscar de donde vienen los sensores.
Lo que importa es que deben estar preparados a recibir datos de distinto tamaño.

Dr. Solana:
No hay problema - estamos acostumbrados a esas cosas.

Mr. X:
Por ultimo, ya le dije que la medida Macondiana es el promedio de las medidas de los microsensores.
Pero estaba simplificando. La medida Macondiana es el resultado de un modelo estadistico de suavización.
Es cierto que la medida depende de los microsensores, pero la síntesis es más compleja que calcular un promedio.
La síntesis de los datos de los microsensores depende del modelo estadístico y un parámetro clave del mismo:
el radio Macondiano de tolerancia.

Dr. Solana:
Wow. Entonces vamos a necesitar una especificación que describe el modelo estadístico.

Mr. X:
En principio si, pero déjeme explicar un poco más.
El radio Macondiano de tolerancia es esencialmente un margen de tolerancia de error en las medidas.
Sin embargo, el radio Macondiano de tolerancia es algo que nuestros cientificos están tratando de determinar.
Porque no es solo una cuestión de estadistica .. es .. es algo que depende del mundo físico.
Me estoy refiriendo a "experimentos en el laboratorio que cuestan millones" ..

Dr. Solana:
Admiro lo avanzado del proyecto.

Mr. X:
Pero no se preocupe, en esta fase del proyecto vamos a asumir un radio y simular el procesamiento.
Después de todo, el valor del radio Macondiano de tolerancia no deberia afectar el costo del mismo.
El valor sugerido es 0.2, pero pueden experimentar con variaciones.

Dr. Solana:
De acuerdo: el costo de procesamiento depende del modelo - muy raramente de un parámetro del mismo.

Mr. X:
Lo cual nos lleva a otra sorpresa: ¡el modelo estadístico no está completamente decidido!
No se asuste: nuestros matemáticos están analizando unos pocos modelos y verificando sus propiedades.
Pero no tenemos que esperar: yo le voy a dar un modelo sencillo para irnos dando una idea del costo.
El modelo final probablemente va a ser más costoso, pero tener una linea de base pronto es útil.

Dr. Solana:
Estoy de acuerdo: es una buena manera de aprovechar el tiempo y a la vez reducir el riesgo del proyecto.

Mr. X:
Muy contento de ver que estamos de acuerdo en esto.
El modelo que sugiero es el siguiente:
- el valor registrado por un microsensor X se compara con el promedio de los otros sensores en el arreglo.
- si la distancia de esos valores es mayor que el radio de tolerancia, el microsensor X es excluido del cómputo final.
- lo anterior se aplica a todos los microsensores en el arreglo: cada uno se compara con el promedio de los otros.
- la medida Macondiana resultante es el promedio de los sensores no excluidos.

Dr. Solana:
Me parece bien: eso va a añadirle costo al procesamiento, como es el caso al agregar complejidad al modelo.
Aunque se me ocurren ideas para hacer ese procesamiento más eficiente de lo que parece.

Mr. X:
No me sorprende: ¡Ud. siempre ha sido un genio en desarrollar algoritmos!

Dr. Solana:
Por favor .. no me haga sentir engreído. :-)

Mr. X:
Claro que no. Vamos a tener una cena .. ¡pagada por la agencia!

Dr. Solana:
¡Con mucho gusto!

---

Notas del Dr. Solana

[1] Supongo que nuestros ingenieros saben a que se refiere con "unidades fundamentales"
https://en.wikipedia.org/wiki/Unit_of_measurement
https://en.wikipedia.org/wiki/Physical_quantity
https://en.wikipedia.org/wiki/Dimensional_analysis

[2]
https://en.wikipedia.org/wiki/Firmware

[3]
https://en.wikipedia.org/wiki/Sensor_array
