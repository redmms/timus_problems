### Way №1 (I suggested first)

1.. Item 1  
2.. Item 2  
3.. Item 3  
3.1 Item 3a  
3.2 Item 3b  
```
let message = 'Hello world';
alert(message);
```
3.2.1 Item 3ba  
```
let message = 'Hello world';
alert(message);
```
4.. Item 3c  
```
let message = 'Hello world';
alert(message);
```

### Way №2 (original with a little modification)

1. Item 1  
2. Item 2  
3. Item 3  
    1. Item 3a  
    2. Item 3b  
        ```
        let message = 'Hello world';
        alert(message);
        ```
        1. Item 3ba  
            ```
            let message = 'Hello world';
            alert(message);
            ```
4. Item 3c  
    ```
    let message = 'Hello world';
    alert(message);
    ```

### Way №3 (most universal)

1. Item 1
2. Item 2  
3. Item 3
<ul>
3.1 Item 3a <br>
3.2 Item 3b <br>
    <div><pre><code>let message = 'Hello world';
    alert(message);</code></pre></div>
<ul>
3.2.1 Item 3ba <br>
    <div><pre><code>let message = 'Hello world';
    alert(message);</code></pre></div>
</ul>
3.3 Item 3c <br>   
    <div><pre><code>let message = 'Hello world';
    alert(message);</code></pre></div>
</ul>

### Way №4 (also possible)

1. Item 1  
2. Item 2  
3. Item 3  
$\hspace{1cm}$ 3.1 Item 3a  
$\hspace{1cm}$ 3.2 Item 3b
```
let message = 'Hello world';
alert(message);
```  
$\hspace$$\hspace$ 3.2.1 Item 3ba  
```
let message = 'Hello world';
alert(message);
```
$\hspace{1cm}$ 3.3 Item 3c     
```
let message = 'Hello world';
alert(message);
```


