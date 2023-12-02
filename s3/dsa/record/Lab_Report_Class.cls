\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{Lab_Report_Class}

\LoadClass{report}
\usepackage{fancyhdr}
\usepackage[T1]{fontenc}
\usepackage[utf8]{inputenc}
\usepackage{graphicx}
\usepackage{xcolor}
\usepackage{titlesec}
\renewcommand\familydefault{\sfdefault}
\usepackage{tgheros}
\usepackage[defaultmono]{droidsansmono}
\usepackage{enumitem}
\usepackage{amsmath,amssymb,amsthm,textcomp}
\usepackage{multicol}
\usepackage{tikz}
\usepackage{lmodern}
\usepackage{color}

\usepackage{hyperref}
\hypersetup{
    colorlinks=true,
    linktoc=all,
    linkcolor=black,
}

\usepackage{geometry}
\geometry{left=22mm,right=22mm,%
    bindingoffset=0mm, top=20mm,bottom=20mm}


\linespread{1.3}

% code listing settings
\usepackage{listings}
\usepackage{xcolor}
\definecolor{atom-one-light-magenta}{RGB}{211, 54, 130}
\definecolor{atom-one-light-blue}{RGB}{38, 139, 210}
\definecolor{atom-one-light-gray}{RGB}{171, 178, 191}
\lstset{
    language=C,
    basicstyle=\ttfamily\small,
    aboveskip={1.0\baselineskip},
    belowskip={1.0\baselineskip},
    columns=fixed,
    extendedchars=true,
    breaklines=true,
    tabsize=4,
    prebreak=\raisebox{0ex}[0ex][0ex]{\ensuremath{\hookleftarrow}},
    frame=lines,
    showtabs=false,
    showspaces=false,
    showstringspaces=false,
    keywordstyle=\color{atom-one-light-blue},
    commentstyle=\color{atom-one-light-gray},
    stringstyle=\color{atom-one-light-magenta},
    numbers=left,
    numberstyle=\small,
    stepnumber=1,
    numbersep=10pt,
    captionpos=t,
    escapeinside={\%*}{*)}
}
\lstset{aboveskip=0pt,belowskip=0pt}

% Title Format
\titleformat
{\chapter}
[display]
{\bfseries\large}
{Experiment No: \ \textnormal{\thechapter}}
{-1ex}
{
    \huge
    \vspace{0ex}
    \centering
}
[
    \vspace{-0.5ex}%
    \rule{\textwidth}{0.3pt}
]
\titlespacing{\chapter}{0pt}{-30pt}{0pt}

% Section Format
% \titleformat{\section}[display]{\bfseries\large}{}{0em}{\underline}[\vspace{0em}]


% Part, for cycles
\usepackage{titlesec}
\titleformat{\part}[display]
{\normalfont\fontsize{24.88}{60}\selectfont\bfseries\centering}
{}
{20pt}
{\underline}
\titlespacing*{\part}{70pt}{80pt}{20pt}

% Experiment with title and date
\newcommand{\experiment}[2]{
    \chapter{#1}
    \begin{tikzpicture}[remember picture, overlay]
        \node[anchor=north east] at ([xshift=-2cm,yshift=-1.78cm]current page.north east) {\large\textbf{Date:}\date{#2}};
    \end{tikzpicture}
}

% Custom footer
\pagestyle{fancy}
\renewcommand{\chaptermark}[1]{\markboth{Experiment \thechapter: #1}{}}
\lhead{}
\chead{}
\rhead{}
\lfoot{}
\cfoot{}
\fancypagestyle{labrecord}{
    \fancyhf{}
    \fancyhead[L]{\vspace{3pt}\nouppercase{\rightmark}} % insert the part name on the left
    \fancyhead[R]{\vspace{3pt}Cycle:\ \thepart\ \ \nouppercase{\leftmark}} % insert the chapter name on the center
    \renewcommand{\headrulewidth}{0.4pt} % add a header rule
    \renewcommand{\footrulewidth}{0pt} % remove the footer rule
    \fancyfoot[C]{\thepage}
    \fancyheadoffset[L]{20pt}
}
\pagestyle{labrecord}