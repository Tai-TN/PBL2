/****************************************************************************
** Meta object code from reading C++ file 'TaskListWidget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../TaskListWidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TaskListWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN14TaskListWidgetE_t {};
} // unnamed namespace

template <> constexpr inline auto TaskListWidget::qt_create_metaobjectdata<qt_meta_tag_ZN14TaskListWidgetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "TaskListWidget",
        "taskStatusChanged",
        "",
        "Task*",
        "task",
        "completed",
        "taskClicked",
        "editTaskRequest",
        "deleteTaskRequest",
        "onTaskItemStatusChanged",
        "onTaskEditClicked",
        "onTaskDeleteClicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'taskStatusChanged'
        QtMocHelpers::SignalData<void(Task *, bool)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Bool, 5 },
        }}),
        // Signal 'taskClicked'
        QtMocHelpers::SignalData<void(Task *)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'editTaskRequest'
        QtMocHelpers::SignalData<void(Task *)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'deleteTaskRequest'
        QtMocHelpers::SignalData<void(Task *)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'onTaskItemStatusChanged'
        QtMocHelpers::SlotData<void(Task *, bool)>(9, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Bool, 5 },
        }}),
        // Slot 'onTaskEditClicked'
        QtMocHelpers::SlotData<void(Task *)>(10, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'onTaskDeleteClicked'
        QtMocHelpers::SlotData<void(Task *)>(11, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<TaskListWidget, qt_meta_tag_ZN14TaskListWidgetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject TaskListWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14TaskListWidgetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14TaskListWidgetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14TaskListWidgetE_t>.metaTypes,
    nullptr
} };

void TaskListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<TaskListWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->taskStatusChanged((*reinterpret_cast< std::add_pointer_t<Task*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 1: _t->taskClicked((*reinterpret_cast< std::add_pointer_t<Task*>>(_a[1]))); break;
        case 2: _t->editTaskRequest((*reinterpret_cast< std::add_pointer_t<Task*>>(_a[1]))); break;
        case 3: _t->deleteTaskRequest((*reinterpret_cast< std::add_pointer_t<Task*>>(_a[1]))); break;
        case 4: _t->onTaskItemStatusChanged((*reinterpret_cast< std::add_pointer_t<Task*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 5: _t->onTaskEditClicked((*reinterpret_cast< std::add_pointer_t<Task*>>(_a[1]))); break;
        case 6: _t->onTaskDeleteClicked((*reinterpret_cast< std::add_pointer_t<Task*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (TaskListWidget::*)(Task * , bool )>(_a, &TaskListWidget::taskStatusChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (TaskListWidget::*)(Task * )>(_a, &TaskListWidget::taskClicked, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (TaskListWidget::*)(Task * )>(_a, &TaskListWidget::editTaskRequest, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (TaskListWidget::*)(Task * )>(_a, &TaskListWidget::deleteTaskRequest, 3))
            return;
    }
}

const QMetaObject *TaskListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TaskListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14TaskListWidgetE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TaskListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void TaskListWidget::taskStatusChanged(Task * _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void TaskListWidget::taskClicked(Task * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void TaskListWidget::editTaskRequest(Task * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void TaskListWidget::deleteTaskRequest(Task * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
QT_WARNING_POP
